#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int num, original, digits, sum, temp;
	for (int num = 0; num <= 100000; num++)
	{
		original = num;
		temp = num;

		//计算数字的位数；
		digits = 0;
		while (temp > 0)
		{
			digits++;
			temp /= 10;
		}

		if (digits == 0) digits = 1;

		temp = original;
		sum = 0;

		//计算各位数字的 n 次方和；
		while (temp > 0)
		{
			int digit = temp % 10;
			sum += (int)pow(digit, digits);
			temp /= 10;
		}

		//判断是否为水仙花数；
		if (sum == original)
		{
			printf("%d\n", original);
		}
	}
	return  0;
}