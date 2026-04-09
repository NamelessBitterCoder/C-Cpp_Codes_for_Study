% 双边带调制
clc;clear;

Ts = 1e-5;
fs = 1/Ts;
f_cutoff = 1500;
t = 0:Ts:0.01;
w_c = 1e4;
A_0 = 3;
A_m = 3;
w = 2000 * pi;

f_t = A_m * sin(w * t);
c_t = cos(2 * pi * w_c * t);
s_DSB = f_t .* c_t;  % 已调DSB信号
s_p = s_DSB .* c_t;  % 已调信号 * 载波信号
s_d = 2 * lowpass(s_p, f_cutoff, fs);  % 解调信号

figure('Name', '双边带调制与解调波形', 'Position', [100 100 1000 800]);

% 1.绘制基带信号
subplot(4, 1, 1);
plot(t, f_t, 'r', 'LineWidth', 1.2);
title('基带信号');
xlabel('时间 t (s)');
ylabel('f(t)');
grid on;
xlim([0, 0.01]);

% 2.绘制DSB已调信号
subplot(4, 1, 2);
plot(t, s_DSB, 'k', 'LineWidth', 1.2);
title('双边带已调信号');
xlabel('时间 t (s)');
ylabel('s_DSB(t)');
grid on;
xlim([0, 0.01]);


% 3.绘制DSB已调信号 * 载波信号
subplot(4, 1, 3);
plot(t, s_p, 'b', 'LineWidth', 1.2);
title('已调信号 * 载波信号');
xlabel('时间 t (s)');
ylabel('s_p(t)');
grid on;
xlim([0, 0.01]);


% 4.绘制解调信号
subplot(4, 1, 4);
plot(t, s_d, 'm', 'LineWidth', 1.2);
title('解调信号');
xlabel('时间 t (s)');
ylabel('s_d(t)');
grid on;
xlim([0, 0.01]);


