#define _CRT_SECURE_NO_WARNINGS 1
#include"SingleList.h"

//1.��������ĳ�ʼ����
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

//2.������������٣�
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

//3.���������ͷ���룻
void SListPushFront(SLNode** pphead, DataType elem)
{
	assert(pphead);
	assert(*pphead);
	//����Ҫ����Ľڵ㣻
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

//4.���������β���룻
void SListPushBack(SLNode* phead, DataType elem)
{
	//����Ҫ����Ľڵ㣻
	SLNode* newnode = malloc(sizeof(SLNode));
	newnode->next = NULL;
	newnode->val = elem;

	
}

//7.��������Ĵ�ӡ��
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