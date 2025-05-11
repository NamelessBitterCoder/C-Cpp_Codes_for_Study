#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int ElemType;
//用动态顺序表实现栈；
typedef struct Stack
{
	ElemType* stk;//动态分配内存；
	int top;//定义栈顶；
	int capacity;//栈的容量；
}Stack;

//1.初始化栈；
void StackInit(Stack* Stk);
//2.删除栈；
void StackDestory(Stack* Stk);
//3.检验栈是否为空
bool StackEmpty(Stack Stk);
//4.返回栈的长度；
int StackSize(Stack Stk);
//5.弹出栈顶元素；
void StackPop(Stack* Stk);
//6.向栈顶插入元素；
void StackPush(Stack* Stk, ElemType elem);
//7.访问栈顶元素；
ElemType StackTop(Stack* Stk);

