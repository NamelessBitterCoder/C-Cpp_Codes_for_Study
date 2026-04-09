clc;clear;

% 方法1：手动计算DTFT
n = 0:4;
x = [2, 3, 4, 3, 2];
k = 0:1000;
w = (pi/500) * k;
X = x * exp(-1j*pi/500).^(n'*k);
magX = abs(X);  % 幅频特性
angX = angle(X);  % 相频特性

% 方法2：用freqz函数计算
b = x;
a = 1;
N = 1001;
[X_freqz, w_freqz] = freqz(b, a, N, 'whole');
magX_freqz = abs(X_freqz);
angX_freqz = angle(X_freqz);

subplot(2, 2, 1);
stem(n, x, '.');
title('例2.32的序列图');
xlabel('n');
ylabel('x(n)');
axis([0, 5, 0, 6]);
grid on;

subplot(2, 2, 2);
plot(w/pi, magX);
title('手动计算幅频特性');
xlabel('以\pi为单位的频率');
ylabel('模值');
grid on;

subplot(2, 2, 4);
plot(w/pi, angX);
title('手动计算的相频特性');
xlabel('以\pi为单位的频率');
ylabel('弧度');
grid on;

% 绘制freqz计算的幅频特性
figure;
subplot(2, 1, 1);
plot(w_freqz/pi, magX_freqz);
title('freqz计算的幅频特性');
xlabel('以\pi为单位的频率');
ylabel('模值');
grid on;

subplot(2, 1, 2);
plot(w_freqz/pi, angX_freqz);
title('freqz计算的相频特性');
xlabel('以\pi为单位的频率');
ylabel('弧度');
grid on;