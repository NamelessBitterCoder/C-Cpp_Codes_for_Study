#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

int main()
{
	//1.测试双向链表的头插；
	printf("1.测试双向链表的头插：\n");
	List l1;
	ListInit(&l1);
	ListPushFront(&l1, 1);
	ListPushFront(&l1, 2);
	ListPushFront(&l1, 3);
	ListPushFront(&l1, 4);
	ListPrint(&l1);
	printf("\n");
	//2.测试双向链表的头删；
	ListPopFront(&l1);
	printf("2.测试双向链表的头删：\n");
	ListPrint(&l1);
	printf("\n");
	ListDestroy(&l1);

	//3..测试双向链表的尾插；
	printf("3.测试双向链表的尾插：\n");
	List l2;
	ListInit(&l2);
	ListPushBack(&l2, 1);
	ListPushBack(&l2, 2);
	ListPushBack(&l2, 3);
	ListPushBack(&l2, 4);
	ListPrint(&l2);
	printf("\n");
	//4.测试双向链表的尾删；
	printf("4.测试双向链表的尾删：\n");
	ListPopBack(&l2);
	ListPrint(&l2);
	printf("\n");
	//5.测试双向链表的查找函数；
	int x = 3;
	Node* find = ListFind(&l2, x);
	printf("5.在链表中查找%d：",x);
	if (find)
	{
		printf("链表中存在值为%d的节点！\n",find->val);
	}
	ListPrint(&l2);
	printf("\n");
	//6.测试双向链表的删除函数；
	printf("6.删除值为%d的节点,删除节点后的链表为：\n",find->val);
	ListDelete(&l2, find);
	ListPrint(&l2);
	printf("\n");
	//7.测试双向链表在指定的节点之前插入节点；
	printf("7.在指定节点之前插入元素：\n");
	Node* insertfront = ListFind(&l2, 1);
	ListInsertFront(insertfront, 3);
	ListPrint(&l2);
	printf("\n");
	//8.测试双向链表在指定的节点之后插入元素；
	printf("8.在指定的元素之后插入元素：\n");
	Node* insertback = ListFind(&l2, 2);
	ListInsertBack(insertback, 4);
	ListPrint(&l2);
	printf("\n");
	ListDestroy(&l2);

	return 0;
}