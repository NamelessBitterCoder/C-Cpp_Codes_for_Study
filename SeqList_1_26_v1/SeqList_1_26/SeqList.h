#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int DataType;
//��̬˳����ʵ�֣�
typedef struct SeqList
{
	DataType* a;
	int size;
	int capacity;
}SL;

//1.˳���ĳ�ʼ����
void SeqListInit(SL* sl);
//2.˳�������٣�
void SeqListDestory(SL* sl);
//3.˳����ͷ�壻
void SeqListPushFront(SL* sl, DataType elem);
//4.˳����β�壻
void SeqListPushBack(SL* sl, DataType elem);
//5.˳����ͷɾ��
void SeqListDeleteFront(SL* sl);
//6.˳����βɾ��
void SeqListDeleteBack(SL* sl);
//7.�������������ֵ��Ԫ��,���ض�ӦԪ�ص��±ꣻ
int SeqListFindValue(SL* sl, DataType elem);
//8.ɾ�����������ֵ��Ԫ�أ����ض�ӦԪ�ص��±ꣻ
bool SeqListEreaseValue(SL* sl, DataType elem);
//9.��ӡ˳���
void SeqListPrint(SL* sl);
