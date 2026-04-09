clc;clear;

Fs = 10000; % 采样频率
t = 1 / Fs:1/Fs:1; % 时间向量
m_t(Fs * 1) = 0; % 初始化调制信号向量
for F = 150:400  % 叠加150~400Hz的正弦波，生成多频率调制信号
    m_t = m_t + 0.003 * sin(2 * pi * F * t) * (400- F);
end
m_t90shift = imag(hilbert(m_t));  % 对调制信号做希尔伯特变换，取虚部得到90°相移后的信号

% 生成1000Hz的正交载波（余弦和正弦分量）
carriercos = cos(2 * pi * 1000 * t);  % 载波cos(w_c t), w_c = 2πx1000
carriersin = sin(2 * pi * 1000 * t);  % 载波sin(w_c t)

% 上边带（USB）信号：s_USB = m(t)cos(ω_c t) - ŷ(t)sin(ω_c t)
s_SSB1 = m_t .* carriercos - m_t90shift .* carriersin;
% 下边带（LSB）信号：s_LSB = m(t)cos(ω_c t) + ŷ(t)sin(ω_c t)
s_SSB2 = m_t .* carriercos + m_t90shift .* carriersin;

figure(1);

% 子图1：载波的余弦（实线）和正弦（虚线）分量
subplot(4, 2, 1);
plot(t(1:100), carriercos(1:100), t(1:100),carriersin(1:100), '--r');

% 子图2：载波余弦分量的频谱（用FFT分析频率分布）
subplot(4, 2, 2);
plot(0:9999, abs(fft(carriercos)));
axis([0 2000 -500 6000]);

% 子图3：调制信号m(t)的时域波形
subplot(4, 2, 3);
plot(t(1:100), m_t(1:100));

% 子图4：调制信号的频谱
subplot(4, 2, 4);
plot(0:9999, abs(fft(m_t)));
axis([0 2000 -500 6000]);

% 子图5：绘制上边带（USB）信号的时域波形
subplot(4, 2, 5);
plot(t(1:100), s_SSB1(1:100));

% 子图6：绘制上边带（USB）信号的频谱
subplot(4, 2, 6);
plot(0:9999, abs(fft(s_SSB1)));
axis([0 2000 -500 6000]);

% 子图7：绘制下边带（LSB）信号的时域波形
subplot(4, 2, 7);
plot(t(1:100), s_SSB2(1:100));

% 子图8：绘制下边带（LSB）信号的频谱
subplot(4, 2, 8);
plot(0:9999, abs(fft(s_SSB2)));
axis([0 2000 -500 6000])