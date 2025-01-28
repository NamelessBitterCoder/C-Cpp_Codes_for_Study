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

//1.��������ĳ�ʼ����
SLNode* SListInit();
//2.������������٣�
void SListDestory(SLNode* phead);
//3.���������ͷ���룻
void SListPushFront(SLNode** phead, DataType elem);
//4.���������β���룻
void SListPushBack(SLNode* phead, DataType elem);
//5.���������ͷɾ����
void SListPopFront(SLNode* phead);
//6.���������βɾ����
void SListPopBack(SLNode* phead);
//7.��������Ĵ�ӡ��
void SListPrint(SLNode* phead);
//8.�����������ֵΪval��Ԫ�أ����ض�Ӧ�Ľڵ㣻
SLNode* SLstFind(SLNode* phead, DataType elem);
//9.����������ָ���Ľڵ�֮ǰ����Ԫ�أ�
void SListInsertFront(SLNode* pnode, DataType elem);
//10.����������ָ���Ľڵ�֮�����Ԫ�أ�
void SListInsertBack(SLNode* pnode, DataType elem);
//11.��������ɾ��ָ���Ľڵ㣻
void SListDelete(SLNode* pnode, DataType elem);