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

//1.��ʼ��˫������
void ListInit(List* L);
//2.����˫������
void ListDestroy(List* L);
//3.˫�����������µĽڵ㣻
Node* CreateNode(DataType elem);
//4.˫�������ͷ�壻
void ListPushFront(List* L, DataType elem);
//5.˫�������β�壻
void ListPushBack(List* L, DataType elem);
//6.˫������Ĵ�ӡ������
void ListPrint(List* L);
//7.˫�������ͷɾ������
void ListPopFront(List* L);
//8.˫�������βɾ������
void ListPopBack(List* L);
//9.��������Ѱ��ֵΪelem�Ľڵ㣬�������ַ��
Node* ListFind(List* L, DataType elem);
//10.��˫��������ɾ��ָ��λ�õĽڵ㣻
void ListDelete(List* L, Node* deletenode);
//11.��ָ���Ľڵ�֮ǰ����һ��Ԫ�أ�
void ListInsertFront(Node* insert, DataType elem);
//12.��ָ���Ľڵ�֮�����һ��Ԫ�أ�
void ListInsertBack(Node* insert, DataType elem);