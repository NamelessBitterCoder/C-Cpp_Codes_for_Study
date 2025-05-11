#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//1.��ʼ�����У�
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

//2.��β����У�
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

	//�������Ϊ�գ�
	if (q->rear == NULL)
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else
	{
		//�����Ϊ�գ���β�壻
		q->rear->next = newnode;
		q->rear = newnode;

	}
	
	q->size++;
}

//3.��ͷ�����У�
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	//���ֻ��һ���ڵ㣻
	if (q->front == q->rear)
	{
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		//����Ƕ���ڵ㣬����ͷɾ��
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}

	q->size--;
}

//4.��ȡ���ж�ͷԪ�أ�
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->val;
}

//5.��ȡ���ж�βԪ�أ�
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->val;
}

//6.��ȡ��������ЧԪ�ظ�����
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
//7.�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0��
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}

//8.���ٶ��У�
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
