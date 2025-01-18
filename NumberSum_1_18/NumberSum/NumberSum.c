#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int temp = n;
	int sum = 0;
	for (int i = 0;i < 5;i++)
	{
		sum += temp;
		temp = temp * 10 + n;
	}
	printf("%d", sum);
	return 0;
}