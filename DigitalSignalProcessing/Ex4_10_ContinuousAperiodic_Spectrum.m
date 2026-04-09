% 数字信号处理第14周实验 例4.10 连续非周期信号的频谱计算
clc;clear;
T0 = [0.05, 0.05, 0.01, 0.01];
L0 = [10, 10, 10, 20];
for i = 1 : 4
    T = T0(i); N = L0(i) / T0(i);
    D = 2 * pi / (N * T);
    n = 0 : N - 1; x = exp(-0.02 * n * T) .* cos(6 * pi * n * T) + 2 * cos(14 * pi * n * T);
    k = floor(-(N - 1) / 2 : (N - 1) / 2);
    X = T * fftshift(fft(x));  % 求x的FFT并移到对称位置
    
    subplot(2, 2, i), plot(k * D, abs(X));
    xlabel('模拟角频率(rad/s)');
    ylabel('幅度');
    grid;
    axis([min(k * D), max(k * D), 0, inf]);
    str = ['T = ', num2str(T), 'N = ', num2str(N)];
    title(str);
end
