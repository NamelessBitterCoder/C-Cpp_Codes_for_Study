#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

int main()
{
	//1.����˫�������ͷ�壻
	printf("1.����˫�������ͷ�壺\n");
	List l1;
	ListInit(&l1);
	ListPushFront(&l1, 1);
	ListPushFront(&l1, 2);
	ListPushFront(&l1, 3);
	ListPushFront(&l1, 4);
	ListPrint(&l1);
	printf("\n");
	//2.����˫�������ͷɾ��
	ListPopFront(&l1);
	printf("2.����˫�������ͷɾ��\n");
	ListPrint(&l1);
	printf("\n");
	ListDestroy(&l1);

	//3..����˫�������β�壻
	printf("3.����˫�������β�壺\n");
	List l2;
	ListInit(&l2);
	ListPushBack(&l2, 1);
	ListPushBack(&l2, 2);
	ListPushBack(&l2, 3);
	ListPushBack(&l2, 4);
	ListPrint(&l2);
	printf("\n");
	//4.����˫�������βɾ��
	printf("4.����˫�������βɾ��\n");
	ListPopBack(&l2);
	ListPrint(&l2);
	printf("\n");
	//5.����˫������Ĳ��Һ�����
	int x = 3;
	Node* find = ListFind(&l2, x);
	printf("5.�������в���%d��",x);
	if (find)
	{
		printf("�����д���ֵΪ%d�Ľڵ㣡\n",find->val);
	}
	ListPrint(&l2);
	printf("\n");
	//6.����˫�������ɾ��������
	printf("6.ɾ��ֵΪ%d�Ľڵ�,ɾ���ڵ�������Ϊ��\n",find->val);
	ListDelete(&l2, find);
	ListPrint(&l2);
	printf("\n");
	//7.����˫��������ָ���Ľڵ�֮ǰ����ڵ㣻
	printf("7.��ָ���ڵ�֮ǰ����Ԫ�أ�\n");
	Node* insertfront = ListFind(&l2, 1);
	ListInsertFront(insertfront, 3);
	ListPrint(&l2);
	printf("\n");
	//8.����˫��������ָ���Ľڵ�֮�����Ԫ�أ�
	printf("8.��ָ����Ԫ��֮�����Ԫ�أ�\n");
	Node* insertback = ListFind(&l2, 2);
	ListInsertBack(insertback, 4);
	ListPrint(&l2);
	printf("\n");
	ListDestroy(&l2);

	return 0;
}