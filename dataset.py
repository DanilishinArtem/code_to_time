import torch
from torch.utils.data import DataLoader
from transformers import RobertaTokenizer, RobertaForSequenceClassification
import numpy as np
from buildSourceCodes import collect_source_file
from config import config



class CodeDataset(torch.utils.data.Dataset):
    def __init__(self, codes, labels, tokenizer):
        self.codes = codes
        self.labels = labels
        self.tokenizer = tokenizer

    def __len__(self):
        return len(self.codes)

    def __getitem__(self, idx):
        code = self.codes[idx]
        label = self.labels[idx]
        # code tokenizing
        inputs = self.tokenizer(code, padding='max_length', truncation=True, return_tensors="pt")
        inputs = {key: val.squeeze(0) for key, val in inputs.items()}
        if config.time_or_classes == 'time':
            inputs['labels'] = torch.tensor(label, dtype=torch.float)
        elif config.time_or_classes == 'classes':
            inputs['labels'] = torch.tensor(label, dtype=torch.long)
        return inputs
    


def build_dataset():
    root_dir = config.path + "/neetcode"
    source_files = collect_source_file(root_dir, config.code_type)
    source_files['time'] = (source_files['time'] - np.mean(source_files['time'])) / np.std(source_files['time'])
    tokenizer = RobertaTokenizer.from_pretrained('microsoft/codebert-base')
    sourceCodes = source_files['sourceCode']
    if config.time_or_classes == 'time':
        labels = source_files['time']
    elif config.time_or_classes == 'classes':
        labels = source_files['class']
    n_classes = (source_files['class'][-1]+1)
    dataset = CodeDataset(sourceCodes, labels, tokenizer)
    train_loader = DataLoader(dataset, batch_size=config.batch_size, shuffle=True)
    
    return train_loader, n_classes