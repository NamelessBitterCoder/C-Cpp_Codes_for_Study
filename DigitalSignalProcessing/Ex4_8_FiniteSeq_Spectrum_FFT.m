% 数据信号处理第14周作业 例4.8 有限长序列的频谱计算
clc;clear;
c = [9, 16, 32, 512];
T = 0.4;
for i = 1:length(c)
    L = c(i);
    x = [ones(1, 5), zeros(1, L-9), ones(1, 4)];
    X = fftshift(fft(x, L));
    D = 2 * pi/(L * T);
    k = floor(-(L-1)/2:(L-1)/2);

    subplot(2, 2, i);
    plot(k * D, real(X));
    xlabel('\omega(rad)');
    ylabel('X(ej\omega)');
    axis([min(k * D), max(k * D), -5, 10]);
    Str = ['K * ',num2str(L)];
    title(Str);
end

