#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//1.初始化队列；
void QueueInit(Que* pqu)
{
	assert(pqu);
	pqu->phead = NULL;
	pqu->ptail = NULL;
	pqu->size = 0;
}

//2.销毁队列；
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

//3.队尾插入元素；
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
//4.队头弹出元素；
void QueuePop(Que* pqu)
{
	//只有一个元素的时候；
	if (pqu->phead == pqu->ptail)
	{
		free(pqu->phead);
		pqu->phead = NULL;
		pqu->ptail = NULL;
		pqu->size = 0;
	}
	else
	{	//又多个元素的时候；
		QNode* next = pqu->phead->next;
		free(pqu->phead);
		pqu->phead = next;
		pqu->size--;
	}
}

//5.判断队列是否为空；
bool QueueEmpty(Que* pqu)
{
	return pqu->phead == NULL;
}

//6.返回队列的长度；
int QueueSize(Que* pqu)
{
	return pqu->size;
}

//7.取出队头的元素；
DataType QueueFront(Que* pqu)
{
	return pqu->phead->val;
}

//8.取出队尾的元素；
DataType QueueBack(Que* pqu)
{
	return pqu->ptail->val;
}