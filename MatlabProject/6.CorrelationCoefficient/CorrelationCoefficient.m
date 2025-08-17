clear;clc;
load test_data.mat

%% 统计描述
MIN = min(data);  % 每一列的最小值
MAX =max(data);  % 每一列的最大值
MEAN = mean(data);  % 每一列的平均值
MEDIAN = median(data);  % 每一列的中位数
SKEWNESS = skewness(data);  % 每一列的偏度
KURTOSIS = kurtosis(data);  % 每一列的峰度
STD = std(data);  % 每一列的标准差
RESULT = [MIN; MAX; MEAN; MEDIAN; SKEWNESS; KURTOSIS; STD];

%% 计算各列之间的相关系数
% 在计算皮尔逊相关系数之前，一定要做出散点图来看两组变量之间是否存在线性关系
% 使用SPSS绘制散点图：图形-旧对话框-散点图/点图-矩阵散点图
R = corrcoef(data);  % 计算皮尔逊相关系数

%% 进行假设检验
x = -4 : 0.1 : 4;
y = tpdf(x, 28);  % 求 t 分布的概率密度值， 28是自由度
figure(1);
plot(x, y, '-');
grid on;
hold on;
tinv(0.975, 28);  % matlab可以求出临界值:2.0484
plot([-2.048, -2.048], [0, tpdf(-2.048, 28)], 'r-');
plot([2.048, 2.048], [0, tpdf(2.048, 28)], 'r-');

%% 计算p值
x = -4 : 0.1 : 4;
y = tpdf(x, 28);
figure(2);
plot(x, y, '-');
grid on;
hold on;
plot([-3.055, -3.055], [0, tpdf(-3.055, 28)], 'r-');
plot([3.055, 3.055], [0, tpdf(3.055, 28)], 'r-');
disp('该检验值对应的p值为：');
disp((1 - tcdf(3.055, 28)) * 2);  % 双侧检验的p值要乘以2；

%% 计算各列之间的相关系数以及p值
[R, P] = corrcoef(data);
% 在EXCEL表格中给数据右上角标上显著性符号吧
P < 0.01  % 标记3颗星的位置
(P < 0.05) .* (P > 0.01)  % 标记2颗星的位置
(P < 0.1) .* (P > 0.05) % % 标记1颗星的位置

%% 正态分布检验
% 正态分布的偏度和峰度
x = normrnd(2, 3, 100, 1);  % 生成100*1的随机向量，每个元素是均值为2，标准差为3的正态分布
skewness(x)  % 偏度
kurtosis(x)  % 峰度
figure(3);
qqplot(x)

% 检验第一列的数据是否为正态分布
[h, p] = jbtest(data(:, 1), 0.05)
[h, p] = jbtest(data(:, 1), 0.01)

% 用循环检验所有列的数据
n_c = size(data, 2);  % 返回数据的列数
H = zeros(1, 6);
P = zeros(1, 6);
for i = 1 : n_c
    [h, p] = jbtest(data(:, 1), 0.05);
    H(i) = h;
    P(i) = p;
end
disp(H)
disp(P)
figure(4);
qqplot(data(:, 1));

%% 斯皮尔曼相关系数
X = [3 8 4 7 2]'
Y = [5 10 9 10 6]'
coeff = corr(X, Y, 'Type', 'Spearman')
% 等价于：
RX = [2 5 3 4 1]
RY = [1 4.5 3 4.5 2]
R = corrcoef(RX, RY)

% 计算矩阵各列的斯皮尔曼相关系数
R = corr(data, 'Type', 'Spearman')

% 大样本下的假设检验
disp(sqrt(590) * 0.0301)
% 计算p值
disp((1 - normcdf(0.7311)) * 2)  % normcdf用来计算标准正态分布的累积概率密度函数

% 相关系数和p值
[R, P] = corr(data, 'type','Spearman')