/*��Ŀ������10���������ҳ����о���ֵ��С�����������͵�һ��������*/
#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	int* p;
	int* min = &a[0];
	for (p = a; p < a + 10; p++)
	{
		if (abs(*min) > abs(*p))
		{
			min = p;
		}
	}
	int t;
	t = a[0];
	a[0] = *min;
	*min = t;
	
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}