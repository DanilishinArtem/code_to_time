import json
import os
from time import time


def collect_source_file(root_dir, type: str):
    source_files = {'nameOfFile': [], 'label': [], 'class': [], 'time': [], 'sourceCode': []}
    class_ = -1
    # recursively walk through the root directory
    for root, dirs, files in os.walk(root_dir):
        for file in files:
            if file.endswith("." + type):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8') as f:
                        source_files['nameOfFile'].append(file_path.split('/')[-1].split('.')[0])
                        if type == "py":
                            label = file_path.split('/')[-2]
                        else:
                            label = file_path.split('/')[-3]
                        if label not in source_files['label']:
                            class_ += 1
                        source_files['class'].append(class_)
                        source_files['label'].append(label)
                        source_files['sourceCode'].append(f.read())


                        if type == "py":
                            start = time()
                            os.system("python3 " + str(file_path))
                            source_files['time'].append((time() - start))
                        else:
                            os.system("g++ " + str(file_path))
                            start = time()
                            os.system("./a.out")
                            source_files['time'].append((time() - start))
                            os.system("rm a.out")
                except (UnicodeDecodeError, IOError):
                    pass
    return source_files


def save_to_json(data, json_file):
    # save collected data to json file
    with open(json_file, 'w', encoding='utf-8') as f:
        json.dump(data, f, indent=4, ensure_ascii=False)


if __name__ == "__main__":
    root_dir = "/home/adanilishin/CodeClassification/neetcode"
    source_files = collect_source_file(root_dir, "py")
    save_to_json(source_files, "source_files.json")