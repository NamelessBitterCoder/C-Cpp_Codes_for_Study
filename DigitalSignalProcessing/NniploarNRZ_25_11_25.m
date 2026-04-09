% 绘制单极性RZ、单极性NRZ、双极性RZ、双极性NRZ
clear;clc;
% 生成单个码元
Ts = 1;
ts = 0.5;
N_sample = 1000;  % 单个码元抽样点数
dt = Ts / N_sample;  % 抽样时间间隔
N = 20;  % 码元数
t = 0 :dt : (N * N_sample - 1) * dt;

RAN = round(rand(1, N));  % 随机生成 N 个0/1序列；
% 单极性NRZ
se1 = [];  % 存储单极性NRZ编码的结果，是不断更新的
for i = 1 : N  % 对于每一个二进制吗，生成器单极性NRZ编码
    if RAN(i) == 1
        se1 = [se1, ones(1, N_sample)];  % 两个向量的拼接，已更新的se1与当前码元的编码拼接
    else
        se1 = [se1, zeros(1, N_sample)];
    end
end

% 单极性RZ
se2 = [];
for i = 1 : N  % 对于每一个二进制吗，生成器单极性NRZ编码
    if RAN(i) == 1
        rz_pulse = [ones(1, N_sample/2), zeros(1, N_sample/2)];
        se2 = [se2, rz_pulse];  % 两个向量的拼接，已更新的se1与当前码元的编码拼接
    else
        se2 = [se2, zeros(1, N_sample)];
    end
end

% 双极性NRZ;
se3 = [];
for i = 1 : N  % 对于每一个二进制吗，生成器单极性NRZ编码
    if RAN(i) == 1
        se3 = [se3, ones(1, N_sample)];  % 两个向量的拼接，已更新的se1与当前码元的编码拼接
    else
        se3 = [se3, -ones(1, N_sample)];
    end
end

% 双极性RZ
se4 = [];
for i = 1 : N  % 对于每一个二进制吗，生成器单极性NRZ编码
    if RAN(i) == 1
        rz_pulse = [ones(1, N_sample/2), zeros(1, N_sample/2)];
        se4 = [se4, rz_pulse];  % 两个向量的拼接，已更新的se1与当前码元的编码拼接
    else
        rz_pulse = [-ones(1, N_sample/2), zeros(1, N_sample/2)];
        se4 = [se4, rz_pulse]; 
    end
end

figure;
subplot(4, 1, 1);
plot(t, se1, 'linewidth', 3);
grid on;
axis([0 20 -1 1]);
title('单极性NRZ');

subplot(4, 1, 2);
plot(t, se2, 'linewidth', 3);
grid on;
axis([0 20 -1 1]);
title('单极性RZ');

subplot(4, 1, 3);
plot(t, se3, 'linewidth', 3);
grid on;
axis([0 20 -1 1]);
title('双极性NRZ');

subplot(4, 1, 4);
plot(t, se4, 'linewidth', 3);
grid on;
axis([0 20 -1 1]);
title('双极性RZ');
disp('RAN:');
disp(RAN);