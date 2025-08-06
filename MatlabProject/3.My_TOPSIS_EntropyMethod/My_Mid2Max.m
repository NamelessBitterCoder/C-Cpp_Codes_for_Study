% 对中间型指标进行正向化的函数
function [posit_x] = My_Mid2Max(x, best)
    %先计算出M，M为x中距离最佳数值的最大距离
    M = max(abs(x - best));
    posit_x = 1 - abs(x - best) / M;
end