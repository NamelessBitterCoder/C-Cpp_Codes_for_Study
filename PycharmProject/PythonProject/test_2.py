import matplotlib.pyplot as plt
import numpy as np
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
x = np.random.randn(1000)
plt.hist(x)
plt.title("直方图")
plt.show()