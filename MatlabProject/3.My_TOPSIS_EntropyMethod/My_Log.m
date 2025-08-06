% 重新定义一个mylog函数，当输入的p中元素为0时，返回0
function [lnp] = My_Log(p)
    n = length(p);  % 向量的长度
    lnp = zeros(n, 1);  % 初始化最后的结果
    for i = 1 : n
        if p(i) == 0  % 如果第i个元素为0
            lnp(i) = 0
        else
            lnp(i) = log(p(i));
    end
end