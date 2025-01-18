#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void PrintDigitsByRecursion(int n)
{
	if (n == 0)
	{
		return;
	}
	PrintDigitsByRecursion(n / 10);
	printf("%d ", n % 10);
}

int main()
{
	int n = 0;
	printf("«Î ‰»Î£∫\n");
	scanf("%d", &n);
	PrintDigitsByRecursion(n);
	return 0;
}