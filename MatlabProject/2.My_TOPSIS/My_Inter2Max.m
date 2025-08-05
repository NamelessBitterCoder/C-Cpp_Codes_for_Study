% 对区间型指标进行正向化的函数
function [posit_x] = My_Inter2Max(x, a, b)
    r_x = size(x, 1); % 计算x的函数用于遍历每一个评价对象的指标；
    M = max([a - min(x), max(x) - b]);
    posit_x = zeros(r_x, 1); % 初始化posit_x的目的是减少处理时间；
    for i = 1 : r_x
        if x < a
            posit_x(i) = 1 - (a - x) / M;
        elseif x > b
            posit_x(i) = 1 - (x - b) / M;
        else
            posit_x(i) = 1;
        end
    end
end