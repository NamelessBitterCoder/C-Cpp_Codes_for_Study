#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int CountDifferentBits(int m, int n)
{
	unsigned int t = m ^ n;
	int count = 0;
	while (t)
	{
		count += t & 1;
		t >>= 1;
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	printf("请输入：\n");
	scanf("%d%d", &m, &n);
	printf("%d和%d的二进制形式不同的位数有：\n",m,n);
	printf("%d", CountDifferentBits(m, n));
	return 0;
}