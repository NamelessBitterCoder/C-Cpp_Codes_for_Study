#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h";
//初始化队列；
void QueueInit(Queue* q)
{
	assert(&q);
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}
//队尾入队列；
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail.\n");
		return;
	}
	newnode->_data = data;
	newnode->_next = NULL;

	if (q->_rear == NULL)
	{
		q->_rear = newnode;
		q->_front = newnode;
		q->size++;
	}
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
		q->size++;
	}
}
//队头出队列；
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_front);

	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = NULL;
		q->_rear = NULL;
		q->size--;
	}
	else
	{
		QNode* dnode = q->_front;
		q->_front = q->_front->_next;
		free(dnode);
		dnode = NULL;
		q->size--;
	}
}
//获取队列头部元素；
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}
//获取队列队尾元素；
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}
//获取队列中有效元素个数；
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
//检测队列是否为空，如果为空返回非零结果，如果非空返回0；
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
//销毁队列；
void QueueDestroy(Queue* q)
{
	assert(q);
	
	QNode* pcur = q->_front;
	while (pcur)
	{
		QNode* dnode = pcur;
		pcur = pcur->_next;
		free(dnode);
		dnode = NULL;
	}
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}