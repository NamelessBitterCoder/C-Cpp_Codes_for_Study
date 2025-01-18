#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int NumberOneCounter(unsigned int n)
{
	int count = 0;
	while (n>0)
	{
		count += n & 1;
		n >>=1;
	}
	return count;
}

int main()
{
	unsigned int n = 0;
	printf("请输入：\n");
	scanf("%ud", &n);
	printf("%d的二进制形式中 1 的个数：%d\n", n, NumberOneCounter(n));
	return 0;
}