import subprocess
import webbrowser
import time
from torch.utils.tensorboard import SummaryWriter
import torch
import torch.nn as nn
import torchvision
import numpy as np
import torch.nn.functional as F



# Step 1: 设置硬件设备，有GPU就使用GPU，没有就使用CPU
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(device)

# Step 2: 导入数据
# MNIST数据在torchvision.datasets中，自带的，可以通过代码在线下载数据
train_ds = torchvision.datasets.MNIST(root = r"E:\CodeForStudy\C-Cpp_Codes_for_Study\MNIST",  # 下载的文件存储的本地目录
                                      train = True,  # True为训练集， False为测试集
                                      transform = torchvision.transforms.ToTensor(),  # 将下载的数据直接转换为张量格式
                                      download = True  # True表示直接在线下载，且下载在root指定的目录中，如果已经下载了，就不会再次下载
                                      )
test_ds = torchvision.datasets.MNIST(root= r"E:\CodeForStudy\C-Cpp_Codes_for_Study\MNIST",
                                     train=False,
                                     transform=torchvision.transforms.ToTensor(),
                                     download=True
                                     )

# Step 3: 加载数据
# PyTorch使用torch.utils.data.DataLoader进行数据加载
batch_size = 32
train_dl = torch.utils.data.DataLoader(dataset = train_ds,  # 要加载的数据集
                                       batch_size = batch_size,  #批次的大小
                                       shuffle = True,  #每个epoch重新排列数据
                                       # 以下的参数有默认值，可以不写
                                       num_workers = 0,  # 用于加载的子进程数，默认值为0。注意：如果在windows中设置为非0，有可能会报错
                                       pin_memory = True,  # True:数据加载器将在返回之前将张量复制到设备/CUDA固定内存中。如果数据元素是自定义类型，或者collate_fn返回一个自定义类型的批次。
                                       drop_last = True,  # 如果数据集大小不能被批次大小整除，则设置为True，这样会删除最后一个不完整的批次。如果设置为 False ，并且数据集的大小不能被批大小整除，则最后一批将保留。（默认值为 False）
                                       timeout = 0,  # 设置数据读取的超时时间，超过这个时间还没读到数据的话就会报错。（默认值为 0 ）
                                       worker_init_fn = None  # 如果不是 None，正将在步长之后的数据加载之间在每个工作子进程上调用，并使用工作 id ([0, num_workers - 1] 中的一个int)的顺序逐个导入。（默认值为 None）
                                       )
# 取一个批次看一下数据格式，数据的shape为[batch_size, channel, height, weight]
# batch_size 已经设定为32, channel，height和weight分别表示图片的通道数，高度和宽度
images, labels = next(iter(train_dl))
print(images.shape)

test_dl = torch.utils.data.DataLoader(dataset = test_ds,  # 要加载的数据集
                                       batch_size = batch_size,  #批次的大小
                                       shuffle = False,  #每个epoch重新排列数据
                                       # 以下的参数有默认值，可以不写
                                       num_workers = 0,  # 用于加载的子进程数，默认值为0。注意：如果在windows中设置为非0，有可能会报错
                                       pin_memory = True,  # True:数据加载器将在返回之前将张量复制到设备/CUDA固定内存中。如果数据元素是自定义类型，或者collate_fn返回一个自定义类型的批次。
                                       drop_last = True,  # 如果数据集大小不能被批次大小整除，则设置为True，这样会删除最后一个不完整的批次。如果设置为 False ，并且数据集的大小不能被批大小整除，则最后一批将保留。（默认值为 False）
                                       timeout = 0,  # 设置数据读取的超时时间，超过这个时间还没读到数据的话就会报错。（默认值为 0 ）
                                       worker_init_fn = None  # 如果不是 None，正将在步长之后的数据加载之间在每个工作子进程上调用，并使用工作 id ([0, num_workers - 1] 中的一个int)的顺序逐个导入。（默认值为 None）
                                       )

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

# Step 4: 加载并打印模型
# 将模型转移到GPU中
model = Model().to(device)

# Step 5: 训练模型
loss_fn = nn.CrossEntropyLoss()  # 创建损失函数
learn_rate = 1e-2  # 设置学习率
opt = torch.optim.SGD(model.parameters(), lr = learn_rate)

# 循环训练
def train(dataloader, model, loss_fn, optimizer):
    size = len(dataloader.dataset)  # 训练集的大小
    num_batches = len(dataloader)  # 批次数目

    train_loss, train_acc = 0, 0  # 初始化训练的损失率和正确率都为0

    for X, Y in dataloader:  # 获取图片及标签
        X, Y = X.to(device), Y.to(device)  # 将图片和标签转换到GPU中

        # 计算预测误差
        pred = model(X)  # 使用CNN网络预测输出pred
        loss = loss_fn(pred, Y)  # 计算预测输出的pred和真实值Y之间的差距

        # 反向传播
        optimizer.zero_grad()  # grad属性归零
        loss.backward()  # 反向传播
        optimizer.step()  # 第一步自动更新

        # 记录acc和loss
        train_acc += (pred.argmax(1) == Y).type(torch.float).sum().item()
        train_loss += loss.item()

    train_acc /= size
    train_loss /= num_batches

    return train_acc, train_loss

# 测试函数，注意测试函数不需要进行梯度下降，不进行网络权重更新，所以不需要传入优化器
def test(dataloader, model, loss_fn):
    size = len(dataloader.dataset)
    num_batches = len(dataloader)
    test_loss, test_acc = 0, 0

    # 不进行训练时，停止梯度更新，节省计算内存消耗
    with torch.no_grad():
        for imgs, targets in dataloader:
            imgs, targets = imgs.to(device), targets.to(device)

            # 计算 loss
            target_pred = model(imgs)
            loss = loss_fn(target_pred, targets)

            test_loss += loss.item()
            test_acc += (target_pred.argmax(1) == targets).type(torch.float).sum().item()
        test_acc /= size
        test_loss /= num_batches

        return test_acc, test_loss

# 正式训练
epochs = 5
train_loss, train_acc, test_loss, test_acc = [], [], [], []

for epoch in range(epochs):
    model.train()
    epoch_train_acc, epoch_train_loss = train(train_dl, model, loss_fn, opt)

    model.eval()
    epoch_test_acc, epoch_test_loss = test(test_dl, model, loss_fn)

    train_acc.append(epoch_train_acc)
    test_acc.append(epoch_test_acc)
    train_loss.append(epoch_train_loss)
    test_loss.append(epoch_test_loss)

    template = 'Epoch: {:2d}, Train_acc: {:.1f}%, Train_loss: {:.3f}, Test_acc: {:.1f}%, Test_loss: {:.3f}'
    print(template.format(epoch + 1, epoch_train_acc * 100, epoch_train_loss, epoch_test_acc * 100, epoch_test_loss))
print('Done')

# 训练结果可视化
writer = SummaryWriter(log_dir = './logs')

# 在训练过程中记录指标
for epoch in range(epochs):
    # 记录训练正确率
    writer.add_scalar('Accuracy/train', train_acc[epoch], epoch)
    # 记录测试正确率
    writer.add_scalar('Accuracy/test', test_acc[epoch], epoch)
    # 记录训练损失
    writer.add_scalar('Loss/train', train_loss[epoch], epoch)
    # 记录测试损失
    writer.add_scalar('Loss/test', test_loss[epoch], epoch)

writer.close()

# 启动TensorBoard并打开浏览器
log_dir = './logs'
# 启动TensorBoard命令
tensorboard_cmd = f'tensorboard --logdir={log_dir} --port=6006'
# 启动TensorBoard进程
process = subprocess.Popen(tensorboard_cmd, shell=True)
# 启动TensorBoard进程
process = subprocess.Popen(tensorboard_cmd, shell =True)

# 等待几秒，确保TensorBoard服务启动
time.sleep(5)

# 打开浏览器访问TensorBoard
webbrowser.open('http://localhost:6006')

# (可选)训练结束后，若想终止TensorBoard进程，可取消下面注释
# process.terminate()