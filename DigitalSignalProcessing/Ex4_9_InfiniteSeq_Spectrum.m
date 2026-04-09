% 数字信号处理第14周实验，例4.9 无限长序列的频谱逼近
clc;clear;
T = 0.4; r = 1; beta = 5e-3; b = 0.01;
while b > beta
    N1 = 2 * r; n1 = 0 : N1 - 1;  % 判断结束循环的条件数据长度
    x1 = 0.5 .^ n1; X1 = fft(x1);  % 长度为N1的序列及其FFT
    N2 = 2 * N1; n2 = 0 : N2 - 1;  % 数据长度加倍为N2
    x2 = 0.5 .^ n2; X2 = fft(x2);  % 长度为N2的序列及其FFT
    k1 = 0 : N2 / 2 - 1; k2 = 2 * k1;  % 确定两序列同一频率的下标
    d = max(abs(X1(k1 + 1) - X2(k2 + 1)));  % 对应的同一频率点上的FFT的误差的最大绝对值
    X1m = max(abs(X1(k1 + 1)));  % X1幅度的最大值
    b = d/X1m;  % 最大相对误差的百分数
    r = r + 1;  % 序列长度加倍
end
k = floor(-(N2 - 1) / 2 : (N2 - 1) / 2); D = 2 * pi / (N2 * T);  % 奈奎斯特频率范围，角频率间隔
subplot(121), plot(k * D, abs(fftshift(X2))); title('幅度谱');
xlabel('模拟角频率(rad/s)'); ylabel('幅度'); grid;
subplot(122), plot(k * D, angle(fftshift(X2))); title('相位谱')
xlabel('模拟角频率(rad/s)'); ylabel('相角'); grid;
