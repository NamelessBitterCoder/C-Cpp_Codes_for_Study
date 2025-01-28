#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;
typedef struct SListNode
{
	struct SListNode* next;
	DataType val;
}SLNode;

//1.单向链表的初始化；
SLNode* SListInit();
//2.单向链表的销毁；
void SListDestory(SLNode* phead);
//3.单向链表的头插入；
void SListPushFront(SLNode** phead, DataType elem);
//4.单向链表的尾插入；
void SListPushBack(SLNode* phead, DataType elem);
//5.单向链表的头删除；
void SListPopFront(SLNode* phead);
//6.单向链表的尾删除；
void SListPopBack(SLNode* phead);
//7.单向链表的打印；
void SListPrint(SLNode* phead);
//8.单向链表查找值为val的元素，返回对应的节点；
SLNode* SLstFind(SLNode* phead, DataType elem);
//9.单向链表在指定的节点之前插入元素；
void SListInsertFront(SLNode* pnode, DataType elem);
//10.单向链表在指定的节点之后插入元素；
void SListInsertBack(SLNode* pnode, DataType elem);
//11.单向链表删除指定的节点；
void SListDelete(SLNode* pnode, DataType elem);