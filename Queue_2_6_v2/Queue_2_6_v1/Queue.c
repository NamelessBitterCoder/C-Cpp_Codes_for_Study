#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//1.初始化队列；
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

//2.队尾入队列；
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("Malloc Fail!\n");
		exit(1);
	}

	newnode->next = NULL;
	newnode->val = data;

	//如果队列为空；
	if (q->rear == NULL)
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else
	{
		//如果不为空，则尾插；
		q->rear->next = newnode;
		q->rear = newnode;

	}
	
	q->size++;
}

//3.队头出队列；
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	//如果只有一个节点；
	if (q->front == q->rear)
	{
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		//如果是多个节点，就是头删；
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}

	q->size--;
}

//4.获取队列队头元素；
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->val;
}

//5.获取队列队尾元素；
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->val;
}

//6.获取队列中有效元素个数；
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
//7.检测队列是否为空，如果为空返回非零结果，如果非空返回0；
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}

//8.销毁队列；
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* pcur = q->front;
	while (pcur)
	{
		QNode* next = pcur->next;
		free(pcur);

		pcur = pcur->next;
	}
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
