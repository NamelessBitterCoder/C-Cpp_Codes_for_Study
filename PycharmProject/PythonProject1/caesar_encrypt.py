#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
《物联网安全》实验一：凯撒加密与暴力破解
功能说明：
1. 凯撒加密：对明文按指定偏移量进行加密
2. 凯撒解密：对密文按指定偏移量进行解密
3. 暴力破解：遍历所有可能偏移量，破解凯撒密文
"""

# 凯撒加密
def caesar_encrypt(plaintext, key):

    ciphertext = ""
    key = key % 26  # 确保偏移量在0-25范围内（处理超出的情况）
    for char in plaintext:
        if char.isupper():
            # 大写字母：A-Z (ASCII 65-90)，循环偏移
            ciphertext += chr((ord(char) - 65 + key) % 26 + 65)
        elif char.islower():
            # 小写字母：a-z (ASCII 97-122)，循环偏移
            ciphertext += chr((ord(char) - 97 + key) % 26 + 97)
        else:
            # 非字母字符（空格、数字、标点）直接保留
            ciphertext += char
    return ciphertext

# 凯撒解密
def caesar_decrypt(ciphertext, key):

    return caesar_encrypt(ciphertext, -key)

# 暴力破解凯撒密文
def brute_force_caesar(ciphertext):

    print("\n===== 暴力破解结果 ======")
    for key in range(1, 26):  # 偏移量
        decrypted_text = caesar_decrypt(ciphertext, key)
        print(f"偏移量 key={key:2d} → 解密结果：{decrypted_text}")
    print("=========================")
    print("提示：找到语义通顺的结果即为原始明文！")

# 获取偏移量
def get_valid_key(prompt):

    while True:
        try:
            key = int(input(prompt))
            key = key % 26
            return key
        except ValueError:
            print(" 输入错误！偏移量必须是整数，请重新输入。")


def main():

    print("=" * 40)
    print("    凯撒加密/解密/暴力破解工具    ")
    print("=" * 40)

    while True:
        # 显示功能菜单
        print("\n请选择要执行的操作：")
        print("1. 凯撒加密")
        print("2. 凯撒解密")
        print("3. 暴力破解凯撒密文")
        print("4. 退出程序")

        # 获取用户选择
        choice = input("\n请输入选项编号（1/2/3/4）：")

        if choice == "1":
            # 加密功能
            plaintext = input("请输入待加密的明文：")
            key = get_valid_key("请输入加密偏移量（整数）：")
            ciphertext = caesar_encrypt(plaintext, key)
            print(f"\n 加密完成！")
            print(f"明文：{plaintext}")
            print(f"密文：{ciphertext}")

        elif choice == "2":
            # 解密功能
            ciphertext = input("请输入待解密的密文：")
            key = get_valid_key("请输入解密偏移量（整数）：")
            plaintext = caesar_decrypt(ciphertext, key)
            print(f"\n 解密完成！")
            print(f"密文：{ciphertext}")
            print(f"明文：{plaintext}")

        elif choice == "3":
            # 暴力破解功能
            ciphertext = input("请输入待破解的凯撒密文：")
            brute_force_caesar(ciphertext)

        elif choice == "4":
            # 退出程序
            print("\n👋 程序已退出，感谢使用！")
            break

        else:
            # 无效选项提示
            print("\n无效选项！请输入1、2、3或4。")

        # 分隔线，提升可读性
        print("\n" + "-" * 40)


# 程序入口
if __name__ == "__main__":
    main()