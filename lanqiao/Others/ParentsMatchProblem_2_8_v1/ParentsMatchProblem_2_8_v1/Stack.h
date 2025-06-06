#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//支持动态增长的栈；
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;  //栈顶；
	int capacity;  //容量
}Stack;

//1.初始化栈；
void StackInit(Stack* ps);
//2.入栈；
void StackPush(Stack* ps, STDataType data);
//3.出栈；
void StackPop(Stack* ps);
//4.获取栈顶元素；
STDataType StackTop(Stack* ps);
//5.获取栈中元素的个数；
int StackSize(Stack* ps);
//6.检测栈是否为空，如果为空返回非零结果，如果不为空返回0；
bool StackEmpty(Stack* ps);
//7.销毁栈；
void StackDestroy(Stack* ps);