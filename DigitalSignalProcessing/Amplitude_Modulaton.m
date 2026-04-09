clc;clear;

fc = 10e3;
Ts = 1e-6;
t = 0:Ts:0.01;
A0 = 3;
omega = 2000 * pi;
Am_values = [3, 6];

% 生成载波信号；
carrier = cos(2 * pi * fc * t);

for Am = Am_values
    modulation = Am * sin(omega * t);
    am_signal = (A0 + modulation) .* carrier;

    figure('Name', sprintf('调幅实验 - 调制信号幅度 A_m = %d', Am));
    % 绘制基带信号 f(t);
    subplot(3, 1, 1);
    plot(t, modulation, 'r', 'LineWidth', 1);
    title(sprintf('基带信号， A_m = %d', Am));
    xlabel('时间 t (s)');
    ylabel('f(t)');
    grid on;
    xlim([0, 0.01]);
    
    % 绘制载波 c(t);
    subplot(3, 1, 2);
    plot(t, carrier, 'b', 'LineWidth', 1);
    title('载波信号');
    xlabel('时间 t (s)');
    ylabel('c(t)');
    grid on;
    xlim([0, 0.01]);

    % 绘制AM调频信号 s_AM(t);
    subplot(3, 1, 3);
    plot(t, am_signal, 'k', 'LineWidth', 1);
    title('AM已调信号');
    xlabel('时间 t (s)');
    ylabel('s_{AM}(t)');
    grid on;
    xlim([0, 0.01]);
end
