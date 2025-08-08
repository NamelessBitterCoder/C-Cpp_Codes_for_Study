#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 1.有符号数与无符号数的比较；
//int i; // 全局变量的初始化默认为 0；
//int main()
//{
//	i--;  //i = -1 转换为无符号整数时，在 32 位系统中会变成 4294967295（unsigned int 的最大值）
//	if (i > sizeof(i)) // 有符号整数会被隐式转换为无符号整数
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}

//2. 异或运算找出单独的数；
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int size = sizeof(a) / sizeof(a[0]);
//	int ret = 0;  //任何数与 0 异或都等于它本身；
//	for (int i = 0; i < size; i++)
//	{
//		ret ^= a[i];  //相同的数异或等于 0； 
//	}
//	printf("single number = %d\n", ret);
//	return 0;
//}

// 3. 打印整数二进制的奇数位和偶数位；
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	printf("%d的二进制表示位：\n", num);
//	for (int i = 31; i >= 0; i--)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("%d的二进制的奇数位为：\n", num);
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("%d的二进制的偶数位为：\n", num);
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	short* p = (short*)arr;
	for (int i = 0; i < 4; i++)
	{
		*(p + i) = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}