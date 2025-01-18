#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int DigitSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return DigitSum(n / 10) + n % 10;
}
int main()
{
	int n = 0;
	printf("请输入：\n");
	scanf("%d", &n);
	printf("%d的数位之和是：%d", n, DigitSum(n));
	return 0;
}