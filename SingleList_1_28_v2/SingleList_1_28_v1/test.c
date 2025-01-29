#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

int main()
{
	//1.����ͷ�庯����
	printf("1.ͷ��õ�������\n");
	SLNode* phead = SListInit();
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	printf("\n");
	//2.����ͷɾ������
	printf("2.ͷɾ��ĵ�������\n");
	SListPopFront(&phead);
	SListPrint(phead);
	printf("\n");
	SListDestory(phead);

	//3.����β�庯����
	printf("3.β��õ�������\n");
	SLNode* s1 = SListInit();
	SListPushBack(&s1, 1);
	SListPushBack(&s1, 2);
	SListPushBack(&s1, 3);
	SListPushBack(&s1, 4);
	SListPrint(s1);
	printf("\n");
	//4.����βɾ������
	printf("4.βɾ��ĵ�������\n");
	SListPopBack(&s1);
	SListPrint(s1);
	printf("\n");
	//5.���Ե�������Ĳ��Һ�����
	int x = 3;
	printf("5.�������в���Ԫ��%d��", x);
	SLNode* find = SListFind(s1, x);
	if (find)
	{
		printf("������������Ԫ��%d!\n", x);
	}
	printf("\n");
	//6.���Ե�������ɾ��ָ��λ�ýڵ�ĺ�����
	printf("6.ɾ��findָ��Ľڵ㣺\n");
	SListDelete(&s1, find);
	SListPrint(s1);
	printf("\n");
	//7.������ָ����λ��֮ǰ����Ԫ�أ�
	printf("7.��insertfrontָ��Ľڵ�֮ǰ����Ԫ�أ�\n");
	SLNode* insertfront = SListFind(s1, 1);
	SListInsertFront(&s1, insertfront, 3);
	SListPrint(s1);
	printf("\n");

	//8.������ָ����λ��֮�����Ԫ�أ�
	printf("8.��insertbackָ��Ľڵ�֮�����Ԫ�أ�\n");
	SLNode* insertback = SListFind(s1, 2);
	SListInsertBack(insertback, 4);
	SListPrint(s1);
	printf("\n");
	SListDestory(s1);

	return 0;
}