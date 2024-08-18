import torch
from torch import nn
from transformers import RobertaForSequenceClassification


class RobertaForClassification(RobertaForSequenceClassification):
    def __init__(self, n_classes):
        model = RobertaForSequenceClassification.from_pretrained('microsoft/codebert-base', num_labels=n_classes)
        super().__init__(model.config)

    def forward(self, input_ids=None, attention_mask=None):
        outputs = super().forward(input_ids=input_ids, attention_mask=attention_mask)
        return outputs




class RobertaForRegression(RobertaForSequenceClassification):
    def __init__(self, n_classes):
        model = RobertaForSequenceClassification.from_pretrained('microsoft/codebert-base', num_labels=n_classes)
        super().__init__(model.config)
        self.model = model
        self.classifier = torch.nn.Linear(n_classes, 1)

    def forward(self, input_ids=None, attention_mask=None):
        outputs = self.model(input_ids=input_ids, attention_mask=attention_mask)
        logits = self.classifier(outputs.logits)
        return logits