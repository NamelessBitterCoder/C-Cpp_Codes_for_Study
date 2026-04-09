clc;clear;
H = [1, 1; 1, -1];
n = 2;
while n < 64
    H = [H, H; H, -H];
    n = n * 2;
end

row_self = 1;
dot_self = sum(H(row_self, :) .* H(row_self, :));

% 选取多对不同行验证点积为 0；
row_pairs = [1, 2; 3, 4; 5, 6; 10, 20; 30, 40];
for i = 1 :size(row_pairs, 1)
    r1 = row_pairs(i, 1);
    r2 = row_pairs(i, 2);
    dot_val = sum(H(r1, :) .* H(r2, :));
    fprintf('第%d行与第%d行的点击：%d\n', r1, r2, dot_val);
end
fprintf("第%d行与自身的点积:：%d\n", row_self, dot_self);

% 随机验证更多对行；
rng('shuffle');
rand_rows = randi([1, 64], 5, 2);
fprintf('\n随机行的点积验证：\n');
for i = 1 : size(rand_rows, 1)
    r1 = rand_rows(i, 1);
    r2 = rand_rows(i, 2);
    dot_val = sum(H(r1, :) .* H(r2, :));
    fprintf('第%d行与第%d行的点积：%d\n', r1, r2, dot_val);
end