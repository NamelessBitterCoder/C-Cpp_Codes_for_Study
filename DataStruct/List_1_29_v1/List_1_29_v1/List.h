#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;
typedef struct ListNode
{
	struct ListNode* pred;
	struct ListNode* succ;
	DataType val;
}Node;

typedef struct List
{
	Node* head;
	Node* tail;
}List;

//1.初始化双向链表；
void ListInit(List* L);
//2.销毁双向链表；
void ListDestroy(List* L);
//3.双向链表申请新的节点；
Node* CreateNode(DataType elem);
//4.双向链表的头插；
void ListPushFront(List* L, DataType elem);
//5.双向链表的尾插；
void ListPushBack(List* L, DataType elem);
//6.双向链表的打印函数；
void ListPrint(List* L);
//7.双向链表的头删函数；
void ListPopFront(List* L);
//8.双向链表的尾删函数；
void ListPopBack(List* L);
//9.在链表中寻找值为elem的节点，返回其地址；
Node* ListFind(List* L, DataType elem);
//10.在双向链表中删除指定位置的节点；
void ListDelete(List* L, Node* deletenode);
//11.在指定的节点之前插入一个元素；
void ListInsertFront(Node* insert, DataType elem);
//12.在指定的节点之后插入一个元素；
void ListInsertBack(Node* insert, DataType elem);