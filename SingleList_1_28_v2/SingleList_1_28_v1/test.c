#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

int main()
{
	//1.测试头插函数；
	printf("1.头插得到的链表：\n");
	SLNode* phead = SListInit();
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	printf("\n");
	//2.测试头删函数；
	printf("2.头删后的到的链表：\n");
	SListPopFront(&phead);
	SListPrint(phead);
	printf("\n");
	SListDestory(phead);

	//3.测试尾插函数；
	printf("3.尾插得到的链表：\n");
	SLNode* s1 = SListInit();
	SListPushBack(&s1, 1);
	SListPushBack(&s1, 2);
	SListPushBack(&s1, 3);
	SListPushBack(&s1, 4);
	SListPrint(s1);
	printf("\n");
	//4.测试尾删函数；
	printf("4.尾删后的到的链表：\n");
	SListPopBack(&s1);
	SListPrint(s1);
	printf("\n");
	//5.测试单向链表的查找函数；
	int x = 3;
	printf("5.在链表中查找元素%d：", x);
	SLNode* find = SListFind(s1, x);
	if (find)
	{
		printf("单向链表中有元素%d!\n", x);
	}
	printf("\n");
	//6.测试单向链表删除指定位置节点的函数；
	printf("6.删除find指向的节点：\n");
	SListDelete(&s1, find);
	SListPrint(s1);
	printf("\n");
	//7.测试在指定的位置之前插入元素；
	printf("7.在insertfront指向的节点之前插入元素：\n");
	SLNode* insertfront = SListFind(s1, 1);
	SListInsertFront(&s1, insertfront, 3);
	SListPrint(s1);
	printf("\n");

	//8.测试在指定的位置之后插入元素；
	printf("8.在insertback指向的节点之后插入元素：\n");
	SLNode* insertback = SListFind(s1, 2);
	SListInsertBack(insertback, 4);
	SListPrint(s1);
	printf("\n");
	SListDestory(s1);

	return 0;
}