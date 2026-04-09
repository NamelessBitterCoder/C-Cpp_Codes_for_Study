clc; clear;
t = 0 : 0.001 : 15;
s = sin(2 * pi * t);
s_noise_1 = awgn(s, -10);
s_noise_2 = awgn(s, 10);

figure(1);
plot(t, s_noise_1,'r-');
title('叠加了信噪比为-10dB的高斯白噪声的正弦信号', 'FontSize', 12);

figure(2);
plot(t, s_noise_2,'b-');
title('叠加了信噪比为10dB的高斯白噪声的正弦信号', 'FontSize', 12);