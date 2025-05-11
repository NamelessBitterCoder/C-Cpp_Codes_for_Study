#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//用链式结构实现队列；
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType val;
}QNode;

//队列的结构；
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

//1.初始化队列；
void QueueInit(Queue* q);
//2.队尾入队列；
void QueuePush(Queue* q, QDataType data);
//3.队头出队列；
void QueuePop(Queue* q);
//4.获取队列队头元素；
QDataType QueueFront(Queue* q);
//5.获取队列队尾元素；
QDataType QueueBack(Queue* q);
//6.获取队列中有效元素个数；
int QueueSize(Queue* q);
//7.检测队列是否为空，如果为空返回非零结果，如果非空返回0；
int QueueEmpty(Queue* q);
//8.销毁队列；
void QueueDestroy(Queue* q);