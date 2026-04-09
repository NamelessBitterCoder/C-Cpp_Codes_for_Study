import matplotlib
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
df = pd.DataFrame({"type":["A", "A", "A", "A", "B", "B", "B", "B"],
                  "value":[11, 14, 13, 16, 9, 8, 6, 10],
                  "date":["t1", "t2", "t3", "t4", "t1", "t2", "t3", "t4"]})
grid = sns.FacetGrid(df, height = 8, hue = "type", aspect = 2)
grid.map(plt.plot, "date", "value")
plt.title("工业时序图", fontsize=22)
plt.tight_layout()
plt.show()