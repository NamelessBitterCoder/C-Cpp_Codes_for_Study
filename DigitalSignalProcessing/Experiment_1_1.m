% 绘制矩形序列
clc; clear;

%% 绘制 x(n) 和 h(n)
n1 = -10 : 12;
n2 = -10 : 12;

% 当n在[0,2]范围内时为1，否则为0
x = (n1 >= 0) & (n1 <= 2);  
x = double(x);  

h = (n2 >= 0) & (n2 <= 3);
h = double(h);

% 绘制矩形序列
figure(1);
stem(n1, x, 'filled'); 
title('x(n)');  
xlabel('n'); 
ylabel('R_3(n)');  
grid on;  
axis([-10 12 -1 2]);

figure(2);
stem(n2, h, 'filled'); 
title('h(n)');  
xlabel('n'); 
ylabel('R_4(n)');  
grid on;  
axis([-10 12 -1 2]);  

%% 计算 x(n) 和 h(n) 的卷积和
x_valid = x(n1 >= 0 & n1 <= 2); 
h_valid = h(n2 >= 0 & n2 <= 3);  

% 使用MATLAB卷积函数conv计算卷积和
y_conv = conv(x_valid, h_valid);  

% 确定卷积结果y(n)的n值范围（卷积后n的范围：0 到 length(x_valid)+length(h_valid)-2）
n_y = 0 : (length(x_valid) + length(h_valid) - 2);  

figure(3);
stem(n_y, y_conv, 'filled');  
title('卷积和 y(n) = x(n) * h(n)'); 
xlabel('n');  
ylabel('y(n)');  
grid on;  
axis([-1 6 0 5]); 

%% 生成并绘制 x(5 - n) 的序列
% 提取x(n)的有效序列
x_valid = x(n1 >= 0 & n1 <= 2);  
n_x = 0:2;  

% 翻褶操作：得到 x(-n)
x_flipped = fliplr(x_valid);  % 翻褶后序列值
n_x_flipped = -n_x;           % 翻褶后对应的n值

% 移位操作：右移5位，得到 x(5-n)
shift = 5;
x_shifted = x_flipped;                % 矩形序列移位后值不变
n_x_shifted = n_x_flipped + shift;    % 移位后n的范围：3,4,5

figure(4);
stem(n_x_shifted, x_shifted, 'filled');
title('x(5-n)');
xlabel('n');
ylabel('x(5-n)');
grid on;
axis([-2 10 -1 2]);  


%% 生成指数序列 y(n) = (-0.9)^n u(n) 并翻褶 
% 生成 y(n)（n ∈ [0,10]，u(n)为单位阶跃，n≥0时有效）
n_y_seq = 0:10;
y = (-0.9).^n_y_seq;  % 元素级幂运算，生成 (-0.9)^n 序列

% 用 fliplr 翻褶 y(n)，得到 y(-n)
y_flipped = fliplr(y);
% 翻褶后对应的n值：原n为0~10，翻褶后n为-10~0
n_y_flipped = -fliplr(n_y_seq);  

figure(5);
subplot(2,1,1);
stem(n_y_seq, y, 'filled');
title('y(n) = (-0.9)^n u(n)');
xlabel('n');
ylabel('y(n)');
grid on;
axis([-1 11 -1 1]);  

subplot(2,1,2);
stem(n_y_flipped, y_flipped, 'filled');
title('翻褶后的 y(-n)');
xlabel('n');
ylabel('y(-n)');
grid on;
axis([-11 1 -1 1]);  

%% 将指数序列扩展5个周期
% 生成原始指数序列：y(n) = (-0.9)^n u(n)，n ∈ [0,10]
n_y_original = 0:10;
y_original = (-0.9).^n_y_original;  % 元素级幂运算，生成(-0.9)^n

% 扩展5个周期
function out = xtide(in, n)
    out = repmat(in, 1, n);
end
y_extended = xtide(y_original, 5);

% 生成扩展后序列的n值范围
n_y_extended = 0:(length(y_original)*5 - 1);  

figure(6);
stem(n_y_extended, y_extended, 'filled');  
title('扩展5个周期后的指数序列 y(n) = (-0.9)^n u(n)');
xlabel('n');  
ylabel('y(n)');  
grid on;  
axis([-1 55 -1 1]);  

%% 生成序列 y(n) = 0.9^n * sin(0.25πn)，-10 ≤ n ≤ 10
n_seq = -10:10;  
y_seq = 0.9.^n_seq .* sin(0.25 * pi * n_seq);  

figure(7);
stem(n_seq, y_seq, 'filled');  
title('序列 y(n) = 0.9^nsin(0.25\pin)');
xlabel('n');  
ylabel('y(n)'); 
grid on;  
axis([-12 12 -4 4]);  