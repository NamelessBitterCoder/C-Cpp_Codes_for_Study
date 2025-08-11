from sklearn.datasets import load_iris
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn import datasets

plt.rcParams["font.family"] = "Microsoft YaHei"

# 调用load_iris函数来加载数据
iris_dataset = load_iris()

# load_iris返回的iris对象是一个Bunch对象，与字典非常相似，里面包含键和值
print(iris_dataset.keys())
# dict_keys(['data', 'target', 'frame', 'target names', 'DESCR', 'feature_names', 'filename', 'data_module'])

# DESCR键对应的值是数据集的简要说明
#print(iris_dataset["DESCR"][:193])

#target_names键对应的值是一个字符串数组，里面包含要预测的花的品种
print("Target names: {}".format(iris_dataset["target_names"]))

#feature_names键对应的值是一个字符串列表，对每一个特征进行了说明
# Feature names: ['sepal length(cm)', 'sepal with(cm)', ’petal length(cm)’, 'petal with(cm)']
print("Feature names: {}".format(iris_dataset['feature_names']))

#数据包含在target和data字段中，data里面是花萼长度，花萼宽度，花瓣长度，花瓣宽度的测量数据，格式为NumPy数组
print("Type of data: {}".format(type(iris_dataset['data'])))

#data数组的每一行对应一朵花，每一列代表每朵花的四个测量数据
print("Shape of data: {}".format(iris_dataset['data'].shape))
# Shape of data: (150, 4)

# 数组中包含150朵不同点的花的测量数据，在机器学习中，个体叫样本（sample）,气属性叫作特征（feature）
# data数组的形状(shape)是样本乘以特征数
print("First five rows of data:\n{}".format(iris_dataset['data'][:5]))

# target数组包含的是测量过的每朵花的品种，也是一个NumPy数组
print("Type of target: {}".format(type(iris_dataset['target'])))
# Type of target: <class 'numpy.ndarray'>

# target是一维数组，每朵花对应其中一个数据
print("Shape of target: {}".format(iris_dataset['target'].shape))
# Shape of target: (150,)

# 品种被准换成从 0 到 2 的整数
# 0 代表 setoas, 1 代表 versicolor, 2 代表virginica
print("target: \n{}".format(iris_dataset['target']))

from sklearn.model_selection import train_test_split

# train_test_split 函数的输出为X_train、X_test、y_train 和y_test，它们都是NumPy数组。X_train 包含75% 的行数据，X_test 包含剩下的25%
X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], random_state = 0)
# X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)

print("X_train shape: {}".format(X_train.shape))  # X_train shape: (112, 4)
print("y_train shape: {}".format(y_train.shape))  # y_train shape: (112,)

print("X_test shape: {}".format(X_test.shape))  # X_test shape: (38, 4)
print("y_test shape: {}".format(y_test.shape))  # y_test shape: (38,)


iris_df = pd.DataFrame(iris_dataset.data, columns=iris_dataset.feature_names)
iris_df['species'] = iris_dataset.target_names[iris_dataset.target]

# 统计描述
print(iris_df.describe())
# 箱线图
iris_df.plot(kind = 'box', subplots = True, layout = (2, 2), sharex = False, sharey = False)
plt.suptitle("箱线图")
plt.show()

# 直方图
# 作用：展示数据的分布情况，常用于观察是否近似正态分布等
iris_df.hist()
plt.suptitle("直方图")
plt.tight_layout()
plt.show()

# 折线图
iris_df.plot()
plt.title("折线图")
plt.tight_layout()
plt.show()

# KDE密度图
# 作用：平滑展示数据分布，比直方图更易看趋势
iris_df.plot(kind = 'kde')
plt.title("KDE密度图")
plt.tight_layout()
plt.show()

# 径向坐标可视化
# 作用：多为数据降维可视化，把特征映射到圆周，直观看类别区分度
ax = pd.plotting.radviz(iris_df,'species', colormap='brg')
ax.add_artist(plt.Circle((0, 0), 1, color = 'r', fill = False))
plt.title("径向坐标可视化")
plt.tight_layout()
plt.show()


