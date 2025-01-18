#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int FactorialByRecursion(int n)
{
	if (n == 1)
	{
		return 1;
	}

	return n * FactorialByRecursion(n - 1);
}

int FactorialByIteration(int n)
{
	int sum = 1;
	for (int i = 1;i <= n;i++)
	{
		sum *= i;
	}
	return sum;
}

int main()
{
	int n = 0;
	printf("请输入：\n");
	scanf("%d", &n);
	printf("%d的阶乘是：%d", n, FactorialByRecursion(n));
	printf("\n");
	printf("%d的阶乘是：%d", n, FactorialByIteration(n));
	return 0;
}