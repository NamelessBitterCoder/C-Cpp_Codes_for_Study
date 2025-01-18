#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int n = 100000;
	for (int i = 1;i < n;i++)
	{
		int original = i;
		int digits = floor(log10(i) + 1);//计算数位；
		int sum = 0;

		//计算各数位之和；
		while (original > 0)
		{
			int digit = original % 10;
			sum += pow(digit, digits);
			original/= 10;
		}

		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}