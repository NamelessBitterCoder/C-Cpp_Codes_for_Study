#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 1.�з��������޷������ıȽϣ�
//int i; // ȫ�ֱ����ĳ�ʼ��Ĭ��Ϊ 0��
//int main()
//{
//	i--;  //i = -1 ת��Ϊ�޷�������ʱ���� 32 λϵͳ�л��� 4294967295��unsigned int �����ֵ��
//	if (i > sizeof(i)) // �з��������ᱻ��ʽת��Ϊ�޷�������
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}

//2. ��������ҳ�����������
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int size = sizeof(a) / sizeof(a[0]);
//	int ret = 0;  //�κ����� 0 ��򶼵���������
//	for (int i = 0; i < size; i++)
//	{
//		ret ^= a[i];  //��ͬ���������� 0�� 
//	}
//	printf("single number = %d\n", ret);
//	return 0;
//}

// 3. ��ӡ���������Ƶ�����λ��ż��λ��
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	printf("%d�Ķ����Ʊ�ʾλ��\n", num);
//	for (int i = 31; i >= 0; i--)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("%d�Ķ����Ƶ�����λΪ��\n", num);
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("%d�Ķ����Ƶ�ż��λΪ��\n", num);
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	short* p = (short*)arr;
	for (int i = 0; i < 4; i++)
	{
		*(p + i) = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}