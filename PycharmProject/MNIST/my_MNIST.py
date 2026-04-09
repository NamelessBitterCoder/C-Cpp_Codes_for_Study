import os
os.environ['KMP_DUPLICATE_LIB_OK']='TRUE'
import warnings
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torchvision
from torchvision import transforms
import numpy as np
import torch.nn.functional as F
import pathlib
from PIL import Image

# Step 1: 设置硬件设备，有GPU就使用GPU，没有就使用CPU
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

# 构建 CNN 神经网络
num_classes = 10  # MNIST数据集中是识别0-9这10个数字，因此是10个类别

class Model(nn.Module):
    def __init__(self):
        super(Model, self).__init__()
        # 特征提取网络
        self.conv1 = nn.Conv2d(1, 32, kernel_size = 3, padding = 1)   # 第一层卷积，卷积核大小为3 * 3
        self.pool1 = nn.MaxPool2d(2)  # 池化层，池化核大小为2 * 2
        self.conv2 = nn.Conv2d(32, 64, kernel_size = 3, padding = 1)  # 第二层卷积，卷积核大小为3 * 3
        self.pool2 = nn.MaxPool2d(2)

        # 分类网络
        self.fc1 = nn.Linear(3136, 64)
        self.fc2 = nn.Linear(64, num_classes)

    def forward(self, x):
        x = self.pool1(F.relu(self.conv1(x)))
        x = self.pool2(F.relu(self.conv2(x)))

        x = torch.flatten(x, start_dim = 1)

        x = F.relu(self.fc1(x))
        x = self.fc2(x)

        return x

# 加载模型
model = Model()
model.loat_state_dice(torch.load('./mnist_cnn_model.pth'))
model.eval()
transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.137,), (0.3081,))])

data_dir = './handwrite'
data_dir = pathlib.Path(data_dir)
# 查找所有.png格式的图片
image_count = len(list(data_dir.glob('*.png')))
print("图片总数量为：", image_count)

plt.rcParams['font.sans-serif'] = ['SimHei']    # 显示中文不标签，不设置会显示中文乱码
plt.rcParams['axes.unicode_minus'] = False      # 显示负号
plt.rcParams['figure.dpi'] = 100                # 分辨率

plt.figure(figsize = (10, 10))
i = 0
for input_file in list(data_dir.glob('*png')):
    image = Image.open(input_file)
    image_resize = image.resize((28, 28))  # 将图片转换成 28 * 28
    image = image_resize.convert('L')  # 转换成灰度图
    image_array = np.array(image)
    print(image_array.shape)

    image = Image.fromarray(image_array)
    image = transform(image)
    image =torch.unsqueeze(image, 0)
    image = image.to(device)
    output = model(image)
    pred = torch.argmax(output, dim = 1)

    image = torch.squeeze(image, 0)
    image = transforms.ToPILImage()(image)

    plt.subplot(10, 4, i + 1)
    plt.tight_layout()
    plt.imshow(image, cmap = 'gray', interpolation = 'none')
    plt.title("实际值：{}, 预测值：{}".format(input_file.stem[:1], pred.item()))
    plt.xticks([])
    plt.yticks([])
    i += 1
plt.show()







