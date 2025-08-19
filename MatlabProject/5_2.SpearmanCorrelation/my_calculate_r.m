function [r] = calculate_r(X, Y)
% 输入值：
    % X：列向量
    % Y：列向量，且与X同纬度
% 返回值：
    % r: X和Y的斯皮尔曼相关系数（第一种定义方法）
    RX = rank_data(X);  % 调用自定义函数rank_data来计算X的等级
    RY = rank_data(Y);  % 调用自定义函数rank_data来计算Y的等级
    d = RX - RY;  % 计算X和Y的等级差
    n = size(X, 1);  % 返回X的行数，也就是样本的个数n
    r = 1 - (6 * sum(d .* d)) / (n * (n ^ 2 - 1));  % 用公式计算斯皮尔曼相关系数
end

