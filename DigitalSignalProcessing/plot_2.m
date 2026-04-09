clear; clc;

t_x = 0:0.1:5;            
x = sin(2*pi*t_x);       

t_y = 0:0.1:8;  
y = sin(2*pi*t_y + pi);   

[R, lags] = xcorr(x, y);  % 对长序列计算互相关
[max_corr, idx] = max(R);      % 找到互相关最大值的索引
best_lag = lags(idx);          % 最佳匹配的滞后量

y_shifted = circshift(y, best_lag);  
y_shifted = y_shifted(1:length(t_x));  

figure(1);
plot(t_x, x, 'bo-', 'LineWidth', 1); hold on; 
plot(t_x, y(1:length(t_x)), 'r*-', 'LineWidth', 1);          
title('匹配前：x = sin(2\pi t) 和 y = sin(2\pi t + \pi)');
xlabel('时间 t'); ylabel('幅度');
grid on;  

figure(2);
plot(t_x, x, 'bo-', 'LineWidth', 1); hold on;  
plot(t_x + 1, y_shifted, 'r*', 'LineWidth', 1);   
title(['匹配后：y序列移位 ', num2str(best_lag), ' 个样本']);
xlabel('时间 t'); ylabel('幅度');
grid on;