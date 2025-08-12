from sklearn.datasets import load_iris
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics
from sklearn import svm
from sklearn.tree import DecisionTreeClassifier
from sklearn.linear_model import LogisticRegression

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
print(iris_df.columns)

# 统计描述
print(iris_df.describe())

# # 箱线图
# iris_df.plot(kind = 'box', subplots = True, layout = (2, 2), sharex = False, sharey = False)
# plt.suptitle("箱线图")
# plt.show()
#
# # 直方图
# # 作用：展示数据的分布情况，常用于观察是否近似正态分布等
# iris_df.hist()
# plt.suptitle("直方图")
# plt.tight_layout()
# plt.show()
#
# # 折线图
# iris_df.plot()
# plt.title("折线图")
# plt.tight_layout()
# plt.show()
#
# # KDE密度图
# # 作用：平滑展示数据分布，比直方图更易看趋势
# iris_df.plot(kind = 'kde')
# plt.title("KDE密度图")
# plt.tight_layout()
# plt.show()
#
# # 径向坐标可视化
# # 作用：多为数据降维可视化，把特征映射到圆周，直观看类别区分度
# ax = pd.plotting.radviz(iris_df,'species', colormap='brg')
# ax.add_artist(plt.Circle((0, 0), 1, color = 'r', fill = False))
# plt.title("径向坐标可视化")
# plt.tight_layout()
# plt.show()
#
# # 小提琴图
# # 作用：Violinplot结合箱线图和KDE的又是，展现分布和密度
# # 设置颜色主题
# antV = ['#1890FF', '#2FC25B', '#F5A623']  # 选 3 种颜色对应 3 个类别
# f, axes = plt.subplots(2, 2, figsize = (8, 8), sharex = True)
# sns.despine(left = True)
#
# sns.violinplot(x = 'species', y = 'sepal length (cm)', data = iris_df, hue='species', palette = antV, ax = axes[0,0])
# sns.violinplot(x = 'species', y = 'sepal width (cm)', data = iris_df, hue='species', palette = antV, ax = axes[0,1])
# sns.violinplot(x = 'species', y = 'petal length (cm)', data = iris_df, hue='species', palette = antV, ax = axes[1,0])
# sns.violinplot(x = 'species', y = 'petal width (cm)', data = iris_df, hue='species', palette = antV, ax = axes[1,1])
# plt.suptitle("小提琴图")
# plt.tight_layout()
# plt.show()
#
# # 点图
# # 作用：展示不同类别特征值趋势
# f, axes = plt.subplots(2, 2, figsize = (8, 8), sharex = True)
# sns.despine(left = True)
# sns.pointplot(x = 'species', y = 'sepal length (cm)', data = iris_df, hue='species', palette = antV, ax = axes[0,0])
# sns.pointplot(x = 'species', y = 'sepal width (cm)', data = iris_df, hue='species', palette = antV, ax = axes[0,1])
# sns.pointplot(x = 'species', y = 'petal length (cm)', data = iris_df, hue='species', palette = antV, ax = axes[1,0])
# sns.pointplot(x = 'species', y = 'petal width (cm)', data = iris_df, hue='species', palette = antV, ax = axes[1,1])
# plt.suptitle("点图")
# plt.tight_layout()
# plt.show()
#
# # 特征关系矩阵图
# # 作用：展示特征两两之间的关系，对角线是单特征分布，非对角线是散点/线性分布
# g = sns.pairplot(data = iris_df, hue = 'species', palette = antV,)
# plt.suptitle("特征关系矩阵图", y = 1.02)
# plt.tight_layout()
# plt.show()
#
# # Andrews曲线
# # 作用：把样本特征转换成傅里叶系数，可视化聚类情况，同类曲线接近
# plt.subplots(figsize = (10, 8))
# pd.plotting.andrews_curves(iris_df, 'species', colormap = 'cool')
# plt.title("Andrews曲线")
# plt.tight_layout()
# plt.show()
#
# # 平行坐标图
# # 作用：多维数据可视化，把特征放在不同坐标轴，连线看类别分布规律
# pd.plotting.parallel_coordinates(iris_df, 'species', colormap = 'brg')
# plt.title("平行坐标图")
# plt.tight_layout()
# plt.show()
#
# # 散点图（带拟合）
# # 作用：看特征间线性关系，同时去分类别
# g = sns.lmplot(data = iris_df, x = 'sepal width (cm)', y = 'sepal length (cm)', hue = 'species', palette = antV)
# plt.title("散点图（带拟合）：萼片宽度 vs 萼片长度")
# plt.tight_layout()
# plt.show()
#
# g = sns.lmplot(data = iris_df, x = 'petal width (cm)', y = 'petal length (cm)', hue = 'species', palette = antV)
# plt.title("散点图（带拟合）：花瓣宽度 vs 花瓣长度")
# plt.tight_layout()
# plt.show()
#
# # 相关性热力图
# # 作用： 展示特征间相关性强弱，颜色越深（或越浅，看配色），相关性越高
# fig, ax = plt.subplots(figsize = (12, 8))
# numeric_cols = ['sepal length (cm)', 'sepal width (cm)', 'petal length (cm)', 'petal width (cm)']
# iris_df_numeric = iris_df[numeric_cols]
# sns.heatmap(iris_df_numeric.corr(), annot = True, cmap = 'GnBu', linewidth = 1, linecolor = 'k',
#             square = True, mask = False, vmin = -1, vmax = 1, cbar_kws = {'orientation': 'vertical'}, cbar = True)
# plt.title("相关性热力图")
# plt.tight_layout()
# plt.show()

# 采用 k 近邻分类法
# k 近邻算法中 k 的含义是，我们可以考虑训练集中与新数据点最近的任意 k 个邻居（比如说，距离最近的3 个或5 个邻居），
# 而不是只考虑最近的那一个。然后，我们可以用这些邻居中数量最多的类别做出预测。
# k 近邻分类算法是在 neighbors 模块 KNeighborsClassifier 类中实现的
# KNeighborsClassifier 最重要的参数就是邻居的数目，这里设为1
knn = KNeighborsClassifier(n_neighbors = 1)

# --------------------- 预测 -------------------
# 想要基于训练集来构建模型，需要调用 knn 对象的fit 方法，输入参数为×_train 和 y_train，二者都是 NumPy 数组，前者包含训练数据，后者包含相应的训练标签
knn.fit(X_train, y_train)

# 将这朵花的测量数据转换为二维NumPy 数组的一行，这是因为scikit-learn的输入数据必须是二维数组
X_new = np.array([[5, 2.8, 1, 0.2]])
print("X_new.shape: {}".format(X_new.shape))

# 调用knn 对象的predict 方法来进行预测
prediction = knn.predict(X_new)
print("Prediction: {}".format(prediction))
print("Prediction target name: {}".format(iris_dataset['target_names'][prediction]))

# --------------------- 评估 --------------------
# 对测试数据中的每朵鸢尾花进行预测，并将预测结果与标签（已知的品种）进行对比
# 可以通过计算精度（accuracy）来衡量模型的优劣，精度就是品种预测正确的花所占的比例
y_pred = knn.predict(X_test)
print("Test set predictions: \n {}".format(y_pred))
# 计算预测精度
print("Test set score: {:.2f}".format(np.mean(y_pred == y_test)))
print("Test set score: {:.2f}".format(metrics.accuracy_score(y_pred, y_test)))
print("Test set score: {:.2f}".format(knn.score(X_test, y_test)))

# -------------------- 模型对比 -------------------
# 使用全部特征
# Support Vector Machine
model = svm.SVC()
model.fit(X_train, y_train)
prediction = model.predict(X_test)
print("The accuary of the SVM is: {:.3f}".format(metrics.accuracy_score(prediction, y_test)))

# Logistic Regression
model = LogisticRegression()
model.fit(X_train, y_train)
prediction = model.predict(X_test)
print("The accuracy of the Logistic Regression is: {:.3f}".format(metrics.accuracy_score(prediction, y_test)))

# Decision Tree
model = DecisionTreeClassifier()
model.fit(X_train, y_train)
prediction = model.predict(X_test)
print("The accuracy of the Decision Tree is: {:.3f}".format(metrics.accuracy_score(prediction, y_test)))

# K-Nearest Neighbours
model = KNeighborsClassifier(n_neighbors = 3)
model.fit(X_train, y_train)
prediction = model.predict(X_test)
print("The accuracy of the KNN is: {:.3f}".format(metrics.accuracy_score(prediction, y_test)))

# 使用部分特征
petal = iris_df[['petal length (cm)', 'petal width (cm)', 'species']]
train_p, test_p = train_test_split(petal, test_size = 0.3, random_state = 0)
X_train_p = train_p[['petal length (cm)', 'petal width (cm)']]
y_train_p = train_p.species
X_test_p = test_p[['petal length (cm)', 'petal width (cm)']]
y_test_p = test_p.species

sepal = iris_df[['sepal length (cm)', 'sepal width (cm)', 'species']]
train_s, test_s = train_test_split(sepal, test_size = 0.3, random_state = 0)
X_train_s = train_s[['sepal length (cm)', 'sepal width (cm)']]
y_train_s = train_s.species
X_test_s = test_s[['sepal length (cm)', 'sepal width (cm)']]
y_test_s = test_s.species

# SVM
model = svm.SVC()
model.fit(X_train_p, y_train_p)
prediction = model.predict(X_test_p)
print("The accuracy of the SVM using Petals is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_p)))

model.fit(X_train_s, y_train_s)
prediction = model.predict(X_test_s)
print("The accuracy of SVM using Sepal is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_s)))

# Logistic Regression
model = LogisticRegression()
model.fit(X_train_p, y_train_p)
prediction = model.predict(X_test_p)
print("The accuracy of Logistic Regression using Petals is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_p)))

model.fit(X_train_s, y_train_s)
prediction = model.predict(X_test_s)
print("The accuracy of Logistic Regression using Sepal is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_s)))

# Decision Tree
model = DecisionTreeClassifier()
model.fit(X_train_p, y_train_p)
prediction = model.predict(X_test_p)
print("The accuracy of Decision Tree using Petals is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_p)))

model.fit(X_train_s, y_train_s)
prediction = model.predict(X_test_s)
print("The accuracy of Decision Tree using Sepal is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_s)))

# DK-Nearest Neighbours
model = KNeighborsClassifier(n_neighbors = 3)
model.fit(X_train_p, y_train_p)
prediction = model.predict(X_test_p)
print("The accuracy of KNN using Petals is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_p)))

model.fit(X_train_s, y_train_s)
prediction = model.predict(X_test_s)
print("The accuracy of KNN using Sepal is: {:.3f}".format(metrics.accuracy_score(prediction, y_test_s)))