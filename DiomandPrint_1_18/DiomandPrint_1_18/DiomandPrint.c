#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int n = 13;
	if (n % 2 == 0)
	{
		printf("请输入奇数。\n");
		exit(1);
	}

	int upper = n / 2 + 1;
	int lower = n / 2;

	//打印上半部分
	for (int i = 0;i < upper;i++)
	{
		//打印空格
		for (int j = 0;j < upper - (i + 1);j++)
		{
			printf(" ");
		}
		//打印符号
		for (int j = 0;j < 1 + 2 * i;j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//打印下半部分
	for (int i = 0;i < lower;i++)
	{
		//打印空格
		for (int j = 0;j < i + 1;j++)
		{
			printf(" ");
		}
		//打印字符
		for (int j = 0;j < 2 * lower - 1 - 2 * i;j++)
		{
			printf("*");
		}
		printf("\n");

	}
	
	return 0;
}