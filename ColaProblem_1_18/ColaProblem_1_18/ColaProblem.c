#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int money = 20;
	int bottles = 0;
	int emptybottles = 0;
	int totaldrinks = 0;

	bottles = money;
	totaldrinks += bottles;
	
	while (bottles>0)
	{
		emptybottles += bottles;//�ȼ����ƿ��������
		bottles = emptybottles / 2;//�ټ������еĿ�ƿ���Ի�������ƿ���֣�
		emptybottles = emptybottles % 2;//�����ʣ��һ����ƿ�ӡ�
		totaldrinks += bottles;//��¼�»����ȵĿ��֣�

	}

	printf("%d", totaldrinks);

	return 0;
}