% 采样并且实现量化
clc;clear;

% 第一步：画出模拟信号；
dt = 0.0001;
t = 0:dt:0.03;
f_h = 50;  % 最高频率；
f_t = cos(2 * pi * f_h * t);
figure(1);
plot(t, f_t);
xlabel('时间 t');
ylabel('f(t)');

% 第二步：画出抽样信号；
f_s = 1000;  % 采样频率
T_s = 1 / f_s;  % 采样间隔
t_s = 0:T_s:0.02;
f_sampling = cos(2 * pi * f_h * t_s);  %对f_t进行抽样，得到采样序列；
figure(2);
stem(t_s, f_sampling);
xlabel('时间 t');
ylabel('f(t)的抽样值');

% 第三步：实现量化，量化电平数 L = 8；
L = 8;  % 量化电平数；
max_a = max(f_sampling);
min_b = min(f_sampling);
delta = (max_a - min_b) / L;
x = zeros(1, L+1);
for i = 1 : L + 1
    x(i) = min_b + (i - 1) * delta;  % 计算L+1个分层电平；
end 
y = zeros(1, L);
for k = 1 : L
    y(k) = (x(k) + x(k + 1)) / 2;  % 计算L个分层电平；
end
f_quantization = zeros(size(f_sampling));
% 判断抽样值属于哪个量化电平
for i = 1 : length(f_sampling)
    for k = 1 : L
        if f_sampling(i) >= x(k) && f_sampling(i) <= x(k + 1)
            f_quantization(i) = y(k);
            break;
        end
    end
end
% 可视化结果；
figure(3);
stem(t_s, f_sampling);
hold on;
stem(t_s, f_quantization);
xlabel('时间 t(s)');
ylabel('f(t)的抽样值和量化值');
legend('抽样值', '量化值');