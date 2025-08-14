clear; clc;
load my_data1;
plot(x, y, 'o');
xlabel('x的值');
ylabel('y的值');
n = size(x, 1);
k = ((n * sum(x .* y)) - sum(y) * sum(x)) / (n * sum(x .* x) - sum(x) * sum(x));
b = (sum(x .* x) * sum(y) - sum(x) * sum(x .* y)) / (n * sum(x .* x) - sum(x) * sum(x));
hold on;  % 继续在之前的图形上绘图；
grid on;  % 添加网格线；

% % 画出y=kx+b的函数图像 plot(x,y)
% % 传统的画法：模拟生成x和y的序列，比如要画出[0,5]上的图形
% xx = 2.5: 0.1 :7  % 间隔设置的越小画出来的图形越准确
% yy = k * xx + b  % k和b都是已知值
% plot(xx,yy,'-')

% 匿名函数的基本用法。
% handle = @(arglist) anonymous_function
% 其中handle为调用匿名函数时使用的名字。
% arglist为匿名函数的输入参数，可以是一个，也可以是多个，用逗号分隔。
% anonymous_function为匿名函数的表达式。
% 举个小例子
%  z=@(x,y) x^2+y^2; 
%  z(1,2) 
% % ans =  5

f = @(x) k * x + b;
% fplot函数可用于画出匿名一元函数的图形。
% fplot(f,xinterval) 将匿名函数f在指定区间xinterval绘图。xinterval =  [xmin xmax] 表示定义域的范围
fplot(f, [2.5, 7]);
legend('样本数据', '拟合函数', 'Location', 'SouthEast');

y_hat = k * x + b;  % y的拟合值；
SSR = sum((y_hat - mean(y)) .^ 2);  % 回归平方和；
SSE = sum((y - y_hat) .^ 2);  % 误差平方和；
SST = sum((y - mean(y)) .^ 2);  % 总体平方和；
R_2 = SSR / SST;  % 拟合优度
disp('回归平方和 SSR = ');
disp(SSR);
disp('误差平方和 SSE = ');
disp(SSE);
disp('总体平方和 SST = ');
disp(SST);
disp('拟合优度 R_2 = ');
disp(R_2);