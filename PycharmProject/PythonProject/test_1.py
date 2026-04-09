import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 替换为系统支持的中文字体
plt.rcParams['axes.unicode_minus'] = False    # 解决负号(-)显示为方块的问题
X = np.linspace(-2, 2, 20)
Y = 2 * X + 1
plt.scatter(X, Y)
plt.title('散点图')
plt.show()