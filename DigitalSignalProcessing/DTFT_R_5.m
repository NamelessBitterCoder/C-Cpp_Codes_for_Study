clc;clear;

% 构造矩形序列
x = ones(1, 5);
N = 1024;

% 使用freqz计算DTFT，'whole'参数指定就算全频率范围[0, 2π)
[H, w] = freqz(x, 1, N, 'whole');

% 计算幅度谱和相位谱
mag_spec = abs(H);  % 幅度谱
phase_spec = angle(H);  % 相位谱

% 绘制幅度谱和相位谱
figure;
% 幅度谱子图
subplot(2, 1, 1);
plot(w/pi, mag_spec);
title('R_5(n)的幅度谱');
xlabel('以\pi为单位的数字频率');
ylabel('幅度');
grid on;

% 相位谱子图
subplot(2, 1, 2);
plot(w/pi, phase_spec);
title('R_5(n)的相位谱');
xlabel('以\pi为单位的数字频率');
ylabel('相位（弧度）');
grid on;