clc;clear;

% 定义系统函数的分子系数
b = [0.2, 0, 0]
% 定义系统函数的分母系数
a = [1, 0.3, -0.25, 0.021];

% 执行部分分式展开
[r, p, c] = residue(b, a);

% 从留数、几点、直接项反推分子和分母系数，验证正确性
[b_recovered, a_recovered] = residue(r, p, c);

fprintf('留数 r = \n');
disp(r);
fprintf('极点 p = \n');
disp(p);
fprintf('直接项 c = \n');
disp(c);
fprintf('反推得到的分子系数 b_recovered = \n');
disp(b_recovered);
fprintf('反推得到的分母系数 a_recovered = \n');
disp(a_recovered);
