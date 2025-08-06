% 计算有n个样本，m个指标的样本所对应的熵权
% 输入
% Z：n * m 的矩阵（要经过正向化和标准化处理，且元素中不存在负数）
% 输出
% W：熵权，1 * m的行向量，表示每一个指标所占的权重大小
function [W] = My_Entropy_Method(Z)
    [n, m] = size(Z);
    D = zeros(1, m); % 初始化保存信息效用值的行向量，节省处理时间
    for i = 1 : m
        x = Z(:, i)  % 取出第i列的指标
        p = x / sum(x);  % 计算概率
        e = - sum(p .* My_Log(p)) / log(n);
        D(i) = 1 - e;  % 计算信息效用值
    end
    W = D ./ sum(D);  %对信息效用值进行归一化
end