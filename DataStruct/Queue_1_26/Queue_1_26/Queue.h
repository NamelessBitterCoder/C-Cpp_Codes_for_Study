#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

//�õ�������ʵ�ֶ��У�
typedef struct QueueNode
{
	struct QueueNode* next;
	DataType val;
}QNode;

//���еĽṹ��1.��ͷ��2.��β��3.���ȣ�
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Que;

//1.��ʼ�����У�
void QueueInit(Que* pqu);
//2.���ٶ��У�
void QueueDestory(Que* pqu);
//3.��β����Ԫ�أ�
void QueuePush(Que* pqu, DataType elem);
//4.��ͷ����Ԫ�أ�
void QueuePop(Que* pqu);
//5.�ж϶����Ƿ�Ϊ�գ�
bool QueueEmpty(Que* pqu);
//6.���ض��еĳ��ȣ�
int QueueSize(Que* pqu);
//7.ȡ����ͷ��Ԫ�أ�
DataType QueueFront(Que* pqu);
//8.ȡ����β��Ԫ�أ�
DataType QueueBack(Que* pqu);