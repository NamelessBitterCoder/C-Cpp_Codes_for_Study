#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

//用单向链表实现队列；
typedef struct QueueNode
{
	struct QueueNode* next;
	DataType val;
}QNode;

//队列的结构：1.队头，2.队尾，3.长度；
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Que;

//1.初始化队列；
void QueueInit(Que* pqu);
//2.销毁队列；
void QueueDestory(Que* pqu);
//3.队尾插入元素；
void QueuePush(Que* pqu, DataType elem);
//4.队头弹出元素；
void QueuePop(Que* pqu);
//5.判断队列是否为空；
bool QueueEmpty(Que* pqu);
//6.返回队列的长度；
int QueueSize(Que* pqu);
//7.取出队头的元素；
DataType QueueFront(Que* pqu);
//8.取出队尾的元素；
DataType QueueBack(Que* pqu);