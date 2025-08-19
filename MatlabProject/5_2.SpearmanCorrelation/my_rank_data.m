function [RX] = rank_data(X)
% 输入值：
    % X：列向量
% 返回值：
    % RX：对应的X的等级
% 举个例子 X = [5 10 9 10 6]'
    [~, index] = sort(X);  % ~表示我们不需要第一个输出值，即排序后的X[5 6 9 10 10]
                           % 这里的 index = [1 5 3 2 4]' 是排序后的X在原向量中的位置 
    [~, RX] = sort(index);  % 对index进行一次升序，得到的rx就是我们想要额等级 rx = [1 4 3 5 2]'
                            % 等级的定义是：原始向量中每个元素在排序后序列中的位置
    for i = 1 : size(X, 1)
        position = (X == X(i));  % 得到X中与X(i)相等的位置，返回一个列向量，向量的值全为1或0
        RX(position == 1) = sum(RX .* position) / sum(position);  
    end
end