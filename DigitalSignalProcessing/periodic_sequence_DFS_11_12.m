clc;clear;

%% 实验内容一 例3.1
N = 5;  % 周期为 5 
n = -10:14;
m = mod(n, N);
R5 = ones(1, N);
x = R5(m + 1);

subplot(2, 1, 1);
stem(n, x,'filled');
xlabel('n');
ylabel('x(n)');
ylim([0, 1.5]);
xlim([-11, 15]);

% 计算周期序列的DFS；
k = 0:N-1;
omega = 2*pi*k/N;
b = R5;
a = 1;
[H, ~] = freqz(b, a, omega);
Xk_DFS = H / N;
k_extended = 0 : N - 1;
m_k = mod(k_extended, N);
Xk_extended = Xk_DFS(m_k + 1);

subplot(2, 1, 2);
stem(k_extended, abs(Xk_extended), 'filled');
xlabel('k');
ylabel('|X̃(k)|');
ylim([0, 1.5]);
xlim([-20, 20]);

%% 实验内容二 例3.2
% 生成周期为N = 10 的矩形脉冲序列
N2 = 10;
x_one_period = [ones(1, 5), zeros(1, 5)];
n2 = -20:29;
m2 = mod(n2, N2);
x2 = x_one_period(m2 + 1);

% 时域图
figure;
subplot(3, 1, 1);
stem(n2, x2, 'filled');
xlabel('n');
ylabel('x(n)');
ylim([-0.2, 1.2]);
xlim([min(n2), max(n2)]);

% 用矩阵法计算DFS
k2 = 0:N2-1;
% 生成旋转因子矩阵
[k_grid, n_grid] = meshgrid(k2, 0:N2-1);
W_N = exp(-1j * 2 * pi /N2);
W_matrix = W_N .^ (k_grid .* n_grid);
% 计算DFS系数
Xk_DFS2 = x_one_period * W_matrix;

% 绘制DFS幅度谱
subplot(3, 1, 2);
stem(k2, abs(Xk_DFS2), 'filled');
xlabel('k');
ylabel('|X(k)|');
title('DFS 幅度谱');
ylim([0, 1.1 * max(abs(Xk_DFS2))]);
xlim([-0.5, N2-0.5]);

% 绘制DFS相位谱
subplot(3, 1, 3);
stem(k2, angle(Xk_DFS2), 'filled');
xlabel('k');
ylabel('arg(X(k))');
title('DFS 相位谱');
ylim([-pi, pi]);
xlim([-0.5, N2-0.5]);
