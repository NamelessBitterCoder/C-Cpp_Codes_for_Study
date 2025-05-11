#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h";
//��ʼ�����У�
void QueueInit(Queue* q)
{
	assert(&q);
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}
//��β����У�
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
//��ͷ�����У�
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
//��ȡ����ͷ��Ԫ�أ�
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}
//��ȡ���ж�βԪ�أ�
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}
//��ȡ��������ЧԪ�ظ�����
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
//�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0��
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
//���ٶ��У�
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