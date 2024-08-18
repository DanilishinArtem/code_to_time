import torch
from config import config
from torch.optim import AdamW
from torch.nn import CrossEntropyLoss
from sklearn.metrics import r2_score

def r2(y_true: torch.Tensor, y_pred: torch.Tensor) -> float:
    ss_res = torch.sum((y_true - y_pred) ** 2)
    ss_tot = torch.sum((y_true - y_true.mean()) ** 2)
    r2 = 1 - ss_res / ss_tot
    return r2.item()

class Trainer:
    def __init__(self, model, epochs, train_dataset, eval_dataset, writer):
        self.model = model.cuda()
        self.epochs = epochs
        self.optimizer = AdamW(model.parameters(), lr=2e-5)
        if config.time_or_classes == 'time':
            self.loss_fn = torch.nn.MSELoss()
        elif config.time_or_classes == 'classes':
            self.loss_fn = CrossEntropyLoss()
        self.train_dataset = train_dataset
        self.eval_dataset = eval_dataset
        self.writer = writer

    def train(self):
        self.model.train()
        total_counter = 0
        for epoch in range(self.epochs):
            total_loss = 0
            total_number = 0
            correct_number = 0
            for batch in self.train_dataset:
                input_ids = batch['input_ids'].cuda()
                attention_mask = batch['attention_mask'].cuda()
                labels = batch['labels'].cuda()
                self.optimizer.zero_grad()

                outputs = self.model(input_ids=input_ids, attention_mask=attention_mask)
                if config.time_or_classes == 'time':
                    outputs = outputs.view(batch['labels'].shape)
                    loss = self.loss_fn(outputs, labels)
                    total_loss = loss.item()
                    r2_ = r2(labels, outputs)
                    print("Loss: " + str(total_loss) + " R2: " + str(r2_))
                    self.writer.add_scalar('Loss/train', total_loss, total_counter)
                    self.writer.add_scalar('Accuracy/r2', r2_, total_counter)

                elif config.time_or_classes == 'classes':
                    loss = self.loss_fn(outputs.logits, labels)
                    total_loss += loss.item()
                    correct_number += (torch.argmax(outputs.logits, dim=1) == labels).sum().item()
                    total_number += len(labels)
                    print("Loss: " + str(total_loss / total_number) + " Accuracy: " + str(correct_number / total_number))
                    self.writer.add_scalar('Loss/train', total_loss / total_number, total_counter)
                    self.writer.add_scalar('Accuracy/train', correct_number / total_number, total_counter)
                loss.backward()
                self.optimizer.step()
                total_counter += 1


    def evaluate(self):
        pass