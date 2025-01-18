#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int FibonacciNumber_Recursion(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return FibonacciNumber_Recursion(n - 1) + FibonacciNumber_Recursion(n - 2);
}

int FibonacciNumber_Iteration(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int a1 = 1, a2 = 1;
	int sum = 0;
	for (int i = 3;i <= n;i++)
	{
		sum = a1 + a2;
		a1 = a2;
		a2 = sum;
	}
	return sum;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("第%d个斐波那契数是：%d", n, FibonacciNumber_Recursion(n));
	printf("\n");
	printf("第%d个斐波那契数是：%d", n, FibonacciNumber_Iteration(n));
	return 0;
}