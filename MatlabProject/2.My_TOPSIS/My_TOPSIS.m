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
    end,
    disp(X);
end