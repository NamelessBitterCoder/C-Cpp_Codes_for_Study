#define _CRT_SECURE_NO_WARNINGS 1
#include"SingleList.h"

//1.单向链表的初始化；
SLNode* SListInit()
{
	SLNode* phead = (SLNode*)malloc(sizeof(SLNode));
	if (phead == NULL)
	{
		perror("Malloc Fail!\n");
		exit(1);
	}
	phead->next = NULL;
	phead->val = -1;
	return phead;
}

//2.单向链表的销毁；
void SListDestory(SLNode* phead)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

//3.单向链表的头插入；
void SListPushFront(SLNode** pphead, DataType elem)
{
	assert(pphead);
	assert(*pphead);
	//申请要插入的节点；
	SLNode* newnode = malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("Malloc Fail!\n");
		exit(1);
	}
	newnode->next = NULL;
	newnode->val = elem;

	newnode->next = (*pphead)->next;
	(*pphead)->next = newnode;
}

//4.单向链表的尾插入；
void SListPushBack(SLNode* phead, DataType elem)
{
	//申请要插入的节点；
	SLNode* newnode = malloc(sizeof(SLNode));
	newnode->next = NULL;
	newnode->val = elem;

	
}

//7.单向链表的打印；
void SListPrint(SLNode* phead)
{
	assert(phead);
	SLNode* cur = phead->next;
	while (cur)
	{
		printf("%d -> ", cur->val);
		cur = cur->next;
	}
}