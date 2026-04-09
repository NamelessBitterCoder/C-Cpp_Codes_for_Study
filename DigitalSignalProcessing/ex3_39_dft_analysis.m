% 习题3.39（2）：模拟信号抽样后的64点DFT分析
clc; clear;

%% 1.设置实验参数
fs = 600;  % 抽样频率
N = 64;  % 抽样点数
T = 1 / fs;  % 抽样间隔
n =  0:N-1;
t = n * T;

%% 2.生成模拟信号的抽样序列x(n)
x = sin(180 * pi * t) + sin(260 * pi * t) + sin(400 * pi * t);

%% 3.计算64点DFT
Xk = fft(x, N);

%% 4.绘制DFT幅度谱
figure;
stem(n, abs(Xk), 'filled');
xlabel('k');
ylabel('|X(k)|');
title('X(k)的幅度谱');
ylim([0, max(abs(Xk)) + 5]);