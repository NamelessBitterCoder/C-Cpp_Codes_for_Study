% 该函数用于计算斯皮尔曼相关系数的p值
function [p] = calculate_p(r, m, kind)
% 输入值：
    % r: 斯皮尔曼相关系数
    % m：样本个数
    % kind: 1 表示dance检验 2 表示双侧检验
% 返回值：
    % p：计算出来的 p 值
    z = abs(r) * sqrt(m - 1);  % 计算检验值
    p = (1 - normcdf(z)) * kind;  % 计算p值，双侧检验的p值是单侧检验的2倍

    % normcdf() 是用于计算正态分布（Normal Distribution）的累积分布函数（Cumulative Distribution Function, CDF） 的函数
    % 对于给定的数值 x，计算正态分布中小于或等于 x 的概率，即 P(X <= x)，
end