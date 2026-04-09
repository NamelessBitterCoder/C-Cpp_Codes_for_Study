% 数字信号处理第12周作业：使用FFT函数分析音频信号
clc; clear;

% 查看音频参数；
info1 = audioinfo('正常频率.wav');
info2 = audioinfo('高频率.wav');
% 读取音频信号
[y1, Fs1] = audioread('正常频率.wav');
[y2, Fs2] = audioread('高频率.wav');

% 绘制两段音频的时域波形图
N1 = length(y1);
t1 = (0:N1-1)/Fs1;
figure(1);
subplot(2, 1, 1);
plot(t1, y1(:,1));
title('正常频率-左声道时域波形');
subplot(2, 1, 2);
plot(t1, y1(:,2));
title('正常频率-右声道时域波形');

figure(2);
N2 = length(y2);  
t2 = (0:N2-1)/Fs2;
subplot(2,1,1); 
plot(t2, y2(:,1)); 
title('高频率-左声道时域波形');
subplot(2,1,2); 
plot(t2, y2(:,2)); 
title('高频率-右声道时域波形');

% 提取正常频率的空白间隔
y1_blank = y1(Fs1*0.5 : Fs1*1.5, 1);
% 提取正常频率的人声部分
y1_voice = y1(Fs1*2 : Fs1*3, 1);

% 提取高频率的空白间隔
y2_blank = y2(Fs2*0.5 : Fs2*1.5, 1);
y2_voice = y2(Fs2*2 : Fs2*3, 1);

% 绘制空白间隔频谱
N_blank1 = length(y1_blank);
Y_blank1 = fft(y1_blank);
abs_Y_blank1 = abs(Y_blank1);
f_blank1 = (0:N_blank1-1)*Fs1/N_blank1;  % 频率轴
figure(3);
subplot(2, 1, 1);
plot(f_blank1(1:N_blank1/2), abs_Y_blank1(1:N_blank1/2));
title('正常频率-空白间隔频谱');
% 绘制人声部分频谱
N_voice1 = length(y1_voice);
Y_voice1 = fft(y1_voice);
abs_Y_voice1 = abs(Y_voice1);
f_voice1 = (0:N_voice1-1)*Fs1/N_voice1;
subplot(2, 1, 2);
plot(f_voice1(1:N_voice1/2), abs_Y_voice1(1:N_voice1/2));
title('正常频率-人声部分频谱');

% 高频率-空白间隔的频谱
figure(4);
N_blank2 = length(y2_blank);
Y_blank2 = fft(y2_blank);  
abs_Y_blank2 = abs(Y_blank2);
f_blank2 = (0:N_blank2-1)*Fs2/N_blank2;
subplot(2,1,1); 
plot(f_blank2(1:N_blank2/2), abs_Y_blank2(1:N_blank2/2));
title('高频率-空白间隔频谱');


% 高频率-人声部分的频谱
N_voice2 = length(y2_voice);
Y_voice2 = fft(y2_voice);  
abs_Y_voice2 = abs(Y_voice2);
f_voice2 = (0:N_voice2-1)*Fs2/N_voice2;
subplot(2,1,2); 
plot(f_voice2(1:N_voice2/2), abs_Y_voice2(1:N_voice2/2));
title('高频率-人声部分频谱');

% 正常频率音频的STFT
figure(5);
subplot(2, 1, 1);
stft(y1(:,1), Fs1);
title('正常频率音频-STFT时频图');
% 高频率音频的STFT
subplot(2, 1, 2);
stft(y2(:,1), Fs2);
title('高频率音频-STFT时频图');