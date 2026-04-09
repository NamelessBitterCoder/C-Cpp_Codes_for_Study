% 圆周卷积和与线性卷积和的对比
clc; clear;

% 1.定义待卷积的序列
x1 = [0, 1, 2];
x2 = [1, 2, 3, 4, 5];

% 2.计算线性卷积
y_linear = conv(x1, x2);

% 3.定义矩阵法计算N点圆周卷积和的的函数
function y_circ = circ_conv_matrix(x1, x2, N)
    % 补零将x1和x2扩展为长度为N的序列
    x1_pad = [x1, zeros(1, N - length(x1))];
    x2_pad = [x2, zeros(1, N - length(x2))];
    
    % 构造x2的循环矩阵（每一行是x2_pad的循环右移的结果）
    circ_mat = zeros(N, N);
    for i = 1:N
        circ_mat(i, :) = circshift(x2_pad, [0, i-1]);
    end

    % 矩阵乘法实现圆周卷积
    y_circ = x1_pad * circ_mat;
end

% 4.计算5点、7点圆周卷积
y_circ5 = circ_conv_matrix(x1, x2, 5);
y_circ7 = circ_conv_matrix(x1, x2, 7);

% 5.画图对比结果
figure('Name', '线性卷积和圆周卷积的对比');

% 子图1：线性卷积
subplot(3, 1, 1);
n_lin = 0:length(y_linear) - 1;
stem(n_lin, y_linear, 'filled');
title('线性卷积和');
xlabel('n');
ylabel('y_linear(n)');
xlim([-0.5, max(n_lin) + 0.5]);

% 子图2：5点圆周卷积和
subplot(3, 1 , 2);
n_circ5 = 0:length(y_circ5) - 1;
stem(n_circ5, y_circ5, 'filled');
title('5点圆周卷积和');
xlabel('n');
ylabel('y_circ5(n)');
xlim([-0.5, max(n_circ5) + 0.5]);

% 子图3：7点圆周卷积和
subplot(3, 1 , 3);
n_circ7 = 0:length(y_circ7) - 1;
stem(n_circ7, y_circ7, 'filled');
title('7点圆周卷积和');
xlabel('n');
ylabel('y_circ7(n)');
xlim([-0.5, max(n_circ7) + 0.5]);