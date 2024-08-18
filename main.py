import torch
from torch.utils.tensorboard import SummaryWriter
from trainer import Trainer
from dataset import build_dataset
from config import config
from model import RobertaForClassification, RobertaForRegression




if __name__ == "__main__":
    train_loader, n_classes = build_dataset()
    # model declaration:
    if config.time_or_classes == 'time':
        model = RobertaForRegression(n_classes=n_classes)
    elif config.time_or_classes == 'classes':
        model = RobertaForClassification(n_classes=n_classes)
    # training:
    writer = SummaryWriter(config.path + '/logs')
    trainer = Trainer(model, config.epochs, train_loader, train_loader, writer)
    trainer.train()
