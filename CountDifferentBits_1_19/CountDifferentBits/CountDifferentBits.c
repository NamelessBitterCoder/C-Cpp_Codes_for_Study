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
	printf("�����룺\n");
	scanf("%d%d", &m, &n);
	printf("%d��%d�Ķ�������ʽ��ͬ��λ���У�\n",m,n);
	printf("%d", CountDifferentBits(m, n));
	return 0;
}