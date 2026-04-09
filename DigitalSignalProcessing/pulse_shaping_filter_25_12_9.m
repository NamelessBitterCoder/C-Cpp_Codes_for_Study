% 第14周通信原理实验课：验证基带传输系统满足理想低通滤波特性
clc; clear;close all;

% 定义参数；
tau0 = 1;
omega_max = pi/tau0;  % H(w)的截止频率；

% 生成采样频率w的采样点
omega = linspace(-2*pi/tau0, 2*pi/tau0, 1000);
H_omega = zeros(size(omega));  % 初始化H(w)；

% 计算H(w)的取值
for i = 1:length(omega)
    if abs(omega(i)) <= omega_max
        H_omega(i) = tau0 * (1 + cos(omega(i)) * tau0);
    else
        H_omega(i) = 0;
    end
end

% 绘制|H(w)|的图形
%figure('Name','H(w)的幅频特性');
subplot(2, 1, 1);
plot(omega, abs(H_omega));
xlabel('omega (rad/s)'); 
ylabel('|H(w)|'); 
grid on;
ax = gca; 
ax.XTick = [-pi/tau0, 0, pi/tau0];
ax.XTickLabel = {'-pi/tau0', '0', 'pi/tau0'};

% 验证等效理想系统特性
Ts = 2 * tau0;  % 码元间隔
omega_verify = linspace(-pi/tau0, pi/tau0, 500);  % 验证区间

% 计算H(w) + H(w-2π/Ts) + H(w+2π/Ts)
H_sum = zeros(size(omega_verify));
for i = 1:length(omega_verify)
    w = omega_verify(i);
    % 计算H(w)
    if abs(w) <= omega_max
        h_w = tau0*(1 + cos(w*tau0));
    else
        h_w = 0;
    end
    % 计算H(w - 2π/Ts)
    w1 = w - pi/tau0;
    if abs(w1) <= omega_max
        h_w1 = tau0 * (1 + cos(w1*tau0));
    else
        h_w1 = 0;
    end
    % 计算H(w + 2π/Ts)
    w2 = w + pi/tau0;
    if abs(w2) <= omega_max
        h_w2 = tau0*(1 + cos(w2*tau0));
    else
        h_w2 = 0;
    end
    H_sum(i) = h_w +h_w1 + h_w2;
end
% 绘制叠加后的结果
%figure('Name','等效理想低通特性验证');
subplot(2, 1, 2);
plot(omega_verify, H_sum);
xlabel('omega (rad/s)');
ylabel('H(w)_sum');
grid on;
ax = gca; 
ax.XTick = [-pi/tau0, 0, pi/tau0];
ax.XTickLabel = {'-pi/tau0', '0', 'pi/tau0'};
ylim([1.9*tau0, 2.1*tau0]);