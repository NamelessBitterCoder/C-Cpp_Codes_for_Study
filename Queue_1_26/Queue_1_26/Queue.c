#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//1.��ʼ�����У�
void QueueInit(Que* pqu)
{
	assert(pqu);
	pqu->phead = NULL;
	pqu->ptail = NULL;
	pqu->size = 0;
}

//2.���ٶ��У�
void QueueDestory(Que* pqu)
{
	assert(pqu);
	if (pqu->phead == NULL)
	{
		return;
	}
	while (pqu->phead)
	{
		QNode* next = pqu->phead->next;
		free(pqu->phead);
		pqu->phead = next;
	}
	pqu->ptail = NULL;
	free(pqu);
	pqu = NULL;
}

//3.��β����Ԫ�أ�
void QueuePush(Que* pqu, DataType elem)
{
	assert(pqu);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	if (newnode == NULL)
	{
		perror("Malloc fail!\n");
		exit(1);
	}
	newnode->val = elem;
	if (pqu->phead == NULL)
	{
		pqu->phead = newnode;
		pqu->ptail = newnode;
	}
	else
	{
		pqu->ptail->next = newnode;
		pqu->ptail = newnode;
	}
	pqu->size++;
}
//4.��ͷ����Ԫ�أ�
void QueuePop(Que* pqu)
{
	//ֻ��һ��Ԫ�ص�ʱ��
	if (pqu->phead == pqu->ptail)
	{
		free(pqu->phead);
		pqu->phead = NULL;
		pqu->ptail = NULL;
		pqu->size = 0;
	}
	else
	{	//�ֶ��Ԫ�ص�ʱ��
		QNode* next = pqu->phead->next;
		free(pqu->phead);
		pqu->phead = next;
		pqu->size--;
	}
}

//5.�ж϶����Ƿ�Ϊ�գ�
bool QueueEmpty(Que* pqu)
{
	return pqu->phead == NULL;
}

//6.���ض��еĳ��ȣ�
int QueueSize(Que* pqu)
{
	return pqu->size;
}

//7.ȡ����ͷ��Ԫ�أ�
DataType QueueFront(Que* pqu)
{
	return pqu->phead->val;
}

//8.ȡ����β��Ԫ�أ�
DataType QueueBack(Que* pqu)
{
	return pqu->ptail->val;
}