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
void SListPushBack(SLNode** pphead, DataType elem)
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

	SLNode* pcur = (*pphead)->next;
	if (pcur == NULL)//�������Ϊ�գ�
	{
		(*pphead)->next = newnode;
	}
	else//�����ж���ڵ㣻
	{
		//pcur�����ߣ�ֱ��pcurָ����������һ���ڵ㣻
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		//��ʱpcur->next = NULL, �������ĩβ�����µ�Ԫ�أ�
		pcur->next = newnode;
	}
	
}

//5.���������ͷɾ����
void SListPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	assert((*pphead)->next);//���ٵ���һ���ڵ㣻
	SLNode* nodeToDelete = (*pphead)->next;
	(*pphead)->next = nodeToDelete->next;
	free(nodeToDelete);
	nodeToDelete = NULL;
}

//6.���������βɾ����
void SListPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	assert((*pphead)->next);//���ٵ���һ���ڵ㣻
	SLNode* pcur = (*pphead)->next;
	//�����������ڶ����ڵ㣻
	while (pcur->next->next)
	{
		pcur = pcur->next;
	}
	//Ҫɾ���������һ���ڵ㣻
	SLNode* nodeToDelete = pcur->next;
	pcur->next = NULL;
	free(nodeToDelete);
	nodeToDelete = NULL;

}

//7.��������Ĵ�ӡ��
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

//8.�����������ֵΪval��Ԫ�أ����ض�Ӧ�Ľڵ㣻
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
//9.����������ָ���Ľڵ�֮ǰ����Ԫ�أ�
void SListInsertFront(SLNode** pphead, SLNode* pnode, DataType elem)
{
	assert(pphead);
	assert(*pphead);
	assert(pnode);
	//�����µĽڵ㣻
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("Malloc Fail!\n");
	}
	newnode->next = NULL;
	newnode->val = elem;

	SLNode* pcur = (*pphead)->next;
	//���ֻ��һ��Ԫ�أ��Ǿ���ͷ�壻
	if (pcur == pnode)
	{
		newnode->next = (*pphead)->next;
		(*pphead)->next = newnode;
	}
	//�ҵ�������ڵ��ǰһ���ڵ㣻
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

//10.����������ָ���Ľڵ�֮�����Ԫ�أ�
void SListInsertBack(SLNode* pnode, DataType elem)
{
	assert(pnode);

	//�����µĽڵ㣻
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

//11.��������ɾ��ָ���Ľڵ㣻
bool SListDelete(SLNode** pphead, SLNode* pnode)
{
	assert(pphead);
	assert((*pphead)->next);//���ٵ���һ��Ԫ�أ�
	assert(pnode);//Ҫɾ���Ľڵ㲻��Ϊ�գ�

	SLNode* pcur = (*pphead)->next;
	//���ֻ��һ��Ԫ�أ�
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
	//û���ҵ���Ӧ��Ԫ�أ�
	return false;

	
}