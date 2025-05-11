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
void SListPushBack(SLNode** pphead, DataType elem)
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

	SLNode* pcur = (*pphead)->next;
	if (pcur == NULL)//如果链表为空；
	{
		(*pphead)->next = newnode;
	}
	else//链表有多个节点；
	{
		//pcur往后走，直到pcur指向链表的最后一个节点；
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		//此时pcur->next = NULL, 在链表的末尾插入新的元素；
		pcur->next = newnode;
	}
	
}

//5.单向链表的头删除；
void SListPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	assert((*pphead)->next);//至少得有一个节点；
	SLNode* nodeToDelete = (*pphead)->next;
	(*pphead)->next = nodeToDelete->next;
	free(nodeToDelete);
	nodeToDelete = NULL;
}

//6.单向链表的尾删除；
void SListPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	assert((*pphead)->next);//至少得有一个节点；
	SLNode* pcur = (*pphead)->next;
	//遍历到倒数第二个节点；
	while (pcur->next->next)
	{
		pcur = pcur->next;
	}
	//要删除的是最后一个节点；
	SLNode* nodeToDelete = pcur->next;
	pcur->next = NULL;
	free(nodeToDelete);
	nodeToDelete = NULL;

}

//7.单向链表的打印；
void SListPrint(SLNode* phead)
{
	assert(phead);
	SLNode* pcur = phead->next;
	while (pcur)
	{
		printf("%d -> ", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}

//8.单向链表查找值为val的元素，返回对应的节点；
SLNode* SListFind(SLNode* phead, DataType elem)
{
	assert(phead);
	
	SLNode* pcur = phead->next;
	while (pcur)
	{
		if (pcur->val == elem)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
//9.单向链表在指定的节点之前插入元素；
void SListInsertFront(SLNode** pphead, SLNode* pnode, DataType elem)
{
	assert(pphead);
	assert(*pphead);
	assert(pnode);
	//申请新的节点；
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("Malloc Fail!\n");
	}
	newnode->next = NULL;
	newnode->val = elem;

	SLNode* pcur = (*pphead)->next;
	//如果只有一个元素，那就是头插；
	if (pcur == pnode)
	{
		newnode->next = (*pphead)->next;
		(*pphead)->next = newnode;
	}
	//找到待插入节点的前一个节点；
	while (pcur->next)
	{
		if (pcur->next==pnode)
		{
			newnode->next = pcur->next;
			pcur->next = newnode;
		}
		pcur = pcur->next;
	}
}

//10.单向链表在指定的节点之后插入元素；
void SListInsertBack(SLNode* pnode, DataType elem)
{
	assert(pnode);

	//申请新的节点；
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("Malloc Fail!\n");
	}
	newnode->next = NULL;
	newnode->val = elem;

	newnode->next = pnode->next;
	pnode->next = newnode;
}

//11.单向链表删除指定的节点；
bool SListDelete(SLNode** pphead, SLNode* pnode)
{
	assert(pphead);
	assert((*pphead)->next);//至少得有一个元素；
	assert(pnode);//要删除的节点不能为空；

	SLNode* pcur = (*pphead)->next;
	//如果只有一个元素；
	if (pcur->next == NULL)
	{
		if (pcur == pnode)
		{
			(*pphead)->next = NULL;
			free(pnode);
			return true;
		}
	}
	while (pcur->next)
	{
		if (pcur->next == pnode)
		{
			pcur->next = pnode->next;
			free(pnode);
			return true;
		}
		pcur = pcur->next;
	}
	//没有找到对应的元素；
	return false;

	
}