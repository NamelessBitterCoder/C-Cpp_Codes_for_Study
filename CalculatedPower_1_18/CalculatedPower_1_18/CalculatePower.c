#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int PowerWithRecursion(int n,int k)
{
	if (n == 1)
	{
		return 1;
	}
	if (k > 0)
	{
		return n * PowerWithRecursion(n,k-1);
	}
	else
	{
		return 1;
	}
	
}

int main()
{
	int n = 2;
	int k = 10;
	printf("%d的%d次方是：%d", n, k, PowerWithRecursion(n, k));
	return 0;
}