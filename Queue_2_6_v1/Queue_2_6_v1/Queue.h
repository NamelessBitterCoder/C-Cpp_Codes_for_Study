#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//����ʽ�ṹʵ�ֶ��У�
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
}QNode;

//���еĽṹ��
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

//1.��ʼ�����У�
void QueueInit(Queue* q);
//2.��β����У�
void QueuePush(Queue* q, QDataType data);
//3.��ͷ�����У�
void QueuePop(Queue* q);
//4.��ȡ���ж�ͷԪ�أ�
QDataType QueueFront(Queue* q);
//5.��ȡ���ж�βԪ�أ�
QDataType QueueBack(Queue* q);
//6.��ȡ��������ЧԪ�ظ�����
int QueueSize(Queue* q);