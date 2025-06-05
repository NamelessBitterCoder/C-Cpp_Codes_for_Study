#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//֧�ֶ�̬������ջ��
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;  //ջ����
	int capacity;  //����
}Stack;

//1.��ʼ��ջ��
void StackInit(Stack* ps);
//2.��ջ��
void StackPush(Stack* ps, STDataType data);
//3.��ջ��
void StackPop(Stack* ps);
//4.��ȡջ��Ԫ�أ�
STDataType StackTop(Stack* ps);
//5.��ȡջ��Ԫ�صĸ�����
int StackSize(Stack* ps);
//6.���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0��
bool StackEmpty(Stack* ps);
//7.����ջ��
void StackDestroy(Stack* ps);