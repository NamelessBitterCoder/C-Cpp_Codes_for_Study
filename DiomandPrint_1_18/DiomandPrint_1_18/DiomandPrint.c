#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int n = 13;
	if (n % 2 == 0)
	{
		printf("������������\n");
		exit(1);
	}

	int upper = n / 2 + 1;
	int lower = n / 2;

	//��ӡ�ϰ벿��
	for (int i = 0;i < upper;i++)
	{
		//��ӡ�ո�
		for (int j = 0;j < upper - (i + 1);j++)
		{
			printf(" ");
		}
		//��ӡ����
		for (int j = 0;j < 1 + 2 * i;j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//��ӡ�°벿��
	for (int i = 0;i < lower;i++)
	{
		//��ӡ�ո�
		for (int j = 0;j < i + 1;j++)
		{
			printf(" ");
		}
		//��ӡ�ַ�
		for (int j = 0;j < 2 * lower - 1 - 2 * i;j++)
		{
			printf("*");
		}
		printf("\n");

	}
	
	return 0;
}