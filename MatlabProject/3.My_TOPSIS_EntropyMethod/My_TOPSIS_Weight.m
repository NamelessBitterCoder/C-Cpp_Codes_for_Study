%第一步：从Excel中复制数据并保存到矩阵 X 中，创建专门的数据文件保存数据，
%需要使用数据时，使用load加载数据。
clear; clc;
load my_data_water_quality.mat;
%%
%第二步：判断矩阵是否需要正向化。
[n, m] = size(X);
disp(['总共有' num2str(n) '个评价对象，' num2str(m) '个评价指标']);
Judge = input(['这' num2str(m) '个评价指标是否需要正向化处理，如果需要请输入1，否则输入0：']);
if Judge == 1
    Position = input('请输入需要进行正向化处理的列，例如第2、3、4列需要处理，请你输入[2, 3, 4]：');
    disp('请输入需要正向化处理的列的指标类型（1.极小型，2.中间型， 3.区间型）');
    type = input('例如：第2列是极小型，第3列是区间型，第6列是中间型，就输入[1,3,2]：');
    %这里需要分别对列进行处理，所以需要用列数循环；
    for i = 1 : size(Position, 2)
        X(:, Position(i)) = My_Positivization(X(:, Position(i)), type(i), Position(i));
    end
    disp('正向化后的矩阵X')
    disp(X);
end

%% 第三步：对正向化后的矩阵进行标准化。
Z = X ./ repmat(sum(X .* X) .^ 0.5, n, 1);
disp('标准化矩阵 Z = ');
disp(Z);

%% 判断是否需要增加权重
judge = input('请问是否需要增加权重，需要请输入1，否则输入0：');
if judge == 1
    judge = input('请问是否需要使用熵权法生成权重，需要请输入1，否则输入0：');
    if judge == 1
        if sum(sum(Z < 0)) > 0
            disp('标准化矩阵中有小于0的元素，需要重新进行标准化。');
            for i = 1 : n
                for j = 1 : m
                    Z(i, j) = (X(i, j) - min(X(:, j))) / (max(X(:, j)) - min(X(:, j)));
                end
            end
            disp('重新标准化后的矩阵Z = ');
            disp(Z);
        else
            W = My_Entropy_Method(Z);
            disp('熵权法所确定的权重为：');
            disp(W);
        end
    else
        disp('如果你有3个指标，你就需要输入3个权重，例如它们分别为0.25,0.25,0.5, 则你需要输入[0.25,0.25,0.5]');
        W = input(['你需要输入' num2str(m) '个权重数，''请以向量的形式输入这' num2str(m) '个权重：']);
        flag = 0;
        while flag == 0
            if abs(sum(W) - 1) < 0.000005 && size(W, 1) == 1 && size(W, 2) == m
                flag = 1;
            else
                W = input('你输入的权重格式不正确，请重新输入。');
            end
        end
    end
else
    W = ones(1, m) ./ m;
end
%% 第四步：计算得分并且对得分进行归一化。
D_P = sum(((repmat(max(Z), n, 1) - Z) .^ 2) .* repmat(W, n, 1), 2) .^ 0.5;  % D+ 与最大值的距离向量
D_N = sum(((repmat(min(Z), n, 1) - Z) .^ 2) .* repmat(W, n, 1), 2) .^ 0.5;  % D- 与最小值的距离向量
% 未归一化的得分
S = D_N ./ (D_N + D_P);
disp('归一化后的得分为stand_S = ：');
stand_S = S / sum(S);
disp(stand_S);
[sorted_S,index] = sort(stand_S ,'descend');
disp('sorted_S = ');
disp(sorted_S);
disp('index = ');
disp(index);
% A = magic(5)  % 幻方矩阵
% M = magic(n)返回由1到n^2的整数构成并且总行数和总列数相等的n×n矩阵。阶次n必须为大于或等于3的标量。
% sort(A)若A是向量不管是列还是行向量，默认都是对A进行升序排列。sort(A)是默认的升序，而sort(A,'descend')是降序排序。
% sort(A)若A是矩阵，默认对A的各列进行升序排列
% sort(A,dim)
% dim=1时等效sort(A)
% dim=2时表示对A中的各行元素升序排列
% A = [2,1,3,8]
% Matlab中给一维向量排序是使用sort函数：sort（A），排序是按升序进行的，其中A为待排序的向量；
% 若欲保留排列前的索引，则可用 [sA,index] = sort(A,'descend') ，排序后，sA是排序好的向量，index是向量sA中对A的索引。
% sA  =  8     3     2     1
% index =  4     3     1     2
