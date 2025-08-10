from sklearn.datasets import load_iris

# 加载数据：load_iris返回的iris对象是一个Bunch对象，与字典非常相似，里面包含键和值
iris_dataset = load_iris()
print(iris_dataset.keys())
# dict_keys(['data', 'target', 'frame', 'target_names', 'DESCR', 'feature_names', 'filename', 'data_module'])


# DESCR键对应的值是数据集的简要说明
print(iris_dataset["DESCR"][:193])

# target_names键对应的值是一个字符串数组，里面包含要预测的花点的品种
# Target names:['setosa' 'versicolor' 'virginica']
print("Target names: {}".format(iris_dataset["target_names"]))

# feature_names键对应的值是一个字符串列表，对每一个特征进行的说明
# Feature names: ['sepal length(cm)' 'sepal width(cm)' 'petal length(cm)' 'petal width(cm)']
print("Feature names: {}".format(iris_dataset['feature_names']))

print("Target shape: {}".format(iris_dataset["target_shape"]))

