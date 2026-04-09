# -*- coding: utf-8 -*-
"""
Python 环境测试脚本
功能：验证解释器、基础语法、函数调用是否正常
"""

def greet(name: str) -> str:
    """一个简单的问候函数"""
    return f"你好，{name}！欢迎来到 Python 的世界。"

def calculate_fibonacci(n: int) -> list:
    """计算斐波那契数列前 n 项"""
    fib_sequence = []
    a, b = 0, 1
    for _ in range(n):
        fib_sequence.append(a)
        a, b = b, a + b
    return fib_sequence

if __name__ == "__main__":
    print("=" * 40)
    print("开始执行 Python 环境测试...")
    print("=" * 40)

    # 1. 测试字符串与函数
    user_name = "测试开发者"
    print("\n[测试1] 函数调用：")
    print(greet(user_name))

    # 2. 测试数学计算与循环
    test_count = 10
    print(f"\n[测试2] 计算斐波那契数列前 {test_count} 项：")
    fib_result = calculate_fibonacci(test_count)
    print(fib_result)

    # 3. 测试列表推导式
    print("\n[测试3] 列表推导式（生成1-10的平方数）：")
    squares = [x ** 2 for x in range(1, 11)]
    print(squares)

    print("\n" + "=" * 40)
    print("✅ 所有测试执行完毕！Python 环境运行正常。")
    print("=" * 40)