% 实验内容（二）：模拟两个站的截断二进制指数退避过程
clear; clc; close all;

N = 10000;              % 模拟实验总次数
total_retrans = 0;      % 累计总重传次数
max_k = 10;             % 退避指数截断阈值（k≥10时固定为10）
max_slot = 2^max_k - 1; % 最大退避时间片（1023）

for exp_idx = 1:N
    retrans_count = 0;  % 本次实验的重传次数
    k = 0;              % 退避指数
    
    while true
        if k < max_k
            current_max = 2^k - 1;  
        else
            current_max = max_slot; 
        end
        
        station1_slot = randi([0, current_max]);  % 站1的退避时间
        station2_slot = randi([0, current_max]);  % 站2的退避时间
        
        % 判断是否成功发送：退避时间不同则成功，否则继续碰撞
        if station1_slot ~= station2_slot
            break;  
        else
            % 仍碰撞：重传次数+1，退避指数+1
            retrans_count = retrans_count + 1;
            k = min(k + 1, max_k);  
        end
    end
    
    % 累加本次实验的重传次数
    total_retrans = total_retrans + retrans_count;
end

avg_retrans = total_retrans / N;
fprintf('模拟%d次实验后，平均重传次数为：%.4f\n', N, avg_retrans);