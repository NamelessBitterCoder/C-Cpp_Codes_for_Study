#pragma once
#include<stdio.h>
#include<assert.h>

typedef int QDataType;
//��ʽ�ṹ����ʾ���У�
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

//���еĽṹ��
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int size;
}Queue;

//��ʼ�����У�
void QueueInit(Queue* q);
//��β����У�
void QueuePush(Queue* q, QDataType data);
//��ͷ�����У�
void QueuePop(Queue* q);
//��ȡ����ͷ��Ԫ�أ�
QDataType QueueFront(Queue* q);
//��ȡ���ж�βԪ�أ�
QDataType QueueBack(Queue* q);
//��ȡ��������ЧԪ�ظ�����
int QueueSize(Queue* q);
//�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0��
int QueueEmpty(Queue* q);
//���ٶ��У�
void QueueDestroy(Queue* q);