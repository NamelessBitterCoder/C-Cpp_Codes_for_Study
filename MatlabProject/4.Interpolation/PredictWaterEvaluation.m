load WaterEvaluationData.mat
x = WaterEvaluationData(1, :);  % %Z的第一行是星期Z: 1     3     5     7     9    11    13    15
[n, m] = size(WaterEvaluationData); 
% Matlab的数组中不能保存字符串，如果要生成字符串数组，就需要使用元胞数组，其用大括号{}定义和引用
ylab = {'周数', '轮虫', '溶氧', 'COD', '水温', 'PH值', '盐度', '透明度', '总碱度', '氯离子', '透明度', '生物量'};
disp(['共有' num2str(n - 1) '个指标需要插值']);
disp('正在对 1 号池进行三次埃尔米特插值，请等待...');
P = zeros(11, 15);
for i = 2 : n  % 从第二行开始都是要进行插值的指标
    y = WaterEvaluationData(i, :)  % 将每一行依次赋值给y
    new_x = 1 : 15;  % 要进行插值的x
    p1 = pchip(x, y, new_x);  % 调用三次埃尔米特插值函数
    subplot(4, 3, i - 1);  % 将所有图依次绘制在 4 * 3 的一幅大图上
    plot(x, y, 'o', new_x, p1, '-'); % 画出每次循环处理后的图像
    axis([0 15, -inf, inf]);  % 设置坐标轴的范围，这里设置横坐标轴0 - 15，纵坐标不变化
    ylabel(ylab{i});  % y轴标题，直接引用元胞数组中的字符串
    P(i - 1, :) = p1;  % 将每次插值后的结果保存在P矩阵中
end
legend('原始数据', '三次埃尔米特插值数据', 'Location', 'SouthEast');
P = [1 : 15; P];  % 把 P 的第一行加上周数
disp('P = ');
disp(P);
