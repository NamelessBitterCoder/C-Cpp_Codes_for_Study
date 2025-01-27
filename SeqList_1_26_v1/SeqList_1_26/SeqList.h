#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int DataType;
//动态顺序表的实现；
typedef struct SeqList
{
	DataType* a;
	int size;
	int capacity;
}SL;

//1.顺序表的初始化；
void SeqListInit(SL* sl);
//2.顺序表的销毁；
void SeqListDestory(SL* sl);
//3.顺序表的头插；
void SeqListPushFront(SL* sl, DataType elem);
//4.顺序表的尾插；
void SeqListPushBack(SL* sl, DataType elem);
//5.顺序表的头删；
void SeqListDeleteFront(SL* sl);
//6.顺序表的尾删；
void SeqListDeleteBack(SL* sl);
//7.查找满足给定的值的元素,返回对应元素的下标；
int SeqListFindValue(SL* sl, DataType elem);
//8.删除满足给定的值的元素，返回对应元素的下标；
bool SeqListEreaseValue(SL* sl, DataType elem);
//9.打印顺序表；
void SeqListPrint(SL* sl);
