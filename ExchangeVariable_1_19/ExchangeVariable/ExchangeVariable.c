#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	printf("�����룺\n");
	scanf("%d%d", &a, &b);
	printf("��ʼʱ��\n");
	printf("a=%d b=%d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("������Ľ����\n");
	printf("a=%d b=%d\n", a, b);
	return 0;
}