import torch
import numpy as np
from matplotlib import pyplot as plt
from torch.utils.data import DataLoader
from torchvision import transforms
from torchvision import datasets
import torch.nn.functional as F

# Step1:归一化
transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.1307,), (0.3081,))])

# Step2:获取数据集
train_dataset = datasets.MNIST(root = 'E:/CodeForStudy/C-Cpp_Codes_for_Study/PythonProject2/MNIST', train = True, download = True, transform = transform)
test_dataset = datasets.MNIST(root = 'E:/CodeForStudy/C-Cpp_Codes_for_Study/PythonProject2/MNIST', train = True, download = True, transform = transform)

# Step3:使用Dataloader加载数据集，shuffle = True 表示打乱数据集
train_loader = DataLoader(train_dataset, batch_size = 64, shuffle = True)
test_loader = DataLoader(train_dataset, batch_size = 64, shuffle = False)
'''
# 展示MNIST数据集
fig = plt.figure()
for i in range(12):
    plt.subplot(3, 4, i + 1)
    plt.tight_layout()
    plt.imshow(train_dataset.train_data[i], cmap = 'gray', interpolation = 'none')
    plt.title('Labels: {}'.format(train_dataset.train_labels[i]))
    plt.xticks([])
    plt.yticks([])
plt.show()'''
