#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	//1.����β�庯����
	/*printf("����β�庯����\n");
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPrint(&s1);
	printf("\n");*/

	//2.����βɾ������
	/*printf("����βɾ������\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");

	SeqListDestory(&s1);*/

	//3.����ͷ�庯����
	/*printf("����ͷ�庯����\n");
	SL s2;
	SeqListInit(&s2);
	SeqListPushFront(&s2, 1);
	SeqListPrint(&s2);
	printf("\n");
	SeqListPushFront(&s2, 2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListPushFront(&s2, 3);
	SeqListPrint(&s2);
	printf("\n");
	SeqListPushFront(&s2, 4);
	SeqListPrint(&s2);
	printf("\n");*/

	//4.����ͷɾ������
	/*printf("����ͷɾ������\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");

	SeqListDestory(&s2);*/

	//5.���Բ���ָ��ֵ��Ԫ�أ�
	SL s3;
	SeqListInit(&s3);
	SeqListPushBack(&s3, 1);
	SeqListPushBack(&s3, 2);
	SeqListPushBack(&s3, 3);
	SeqListPushBack(&s3, 4);
	SeqListPrint(&s3);
	printf("\n");
	
	//�ҵ�ָ��ֵ��Ԫ�أ�
	int x = 3;
	printf("��˳����в���ֵΪ%d��Ԫ�أ�",x);
	int find = SeqListFindValue(&s3, x);
	if (find >= 0)
	{
		printf("�ҵ��ˣ���ӦԪ�ص��±�Ϊ��%d\n", find);
	}
	else
	{
		printf("û���ҵ���Ӧ��Ԫ�أ�\n");
	}

	//6.����ɾ��ָ��ֵ��Ԫ�أ�
	printf("ɾ��ֵΪ%d��Ԫ�أ�",x);
	int ret= SeqListEreaseValue(&s3, x);
	if (ret)
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
	}

	SeqListDestory(&s3);

	return 0;
}