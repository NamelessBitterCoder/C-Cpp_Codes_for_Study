#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int ElemType;
//�ö�̬˳���ʵ��ջ��
typedef struct Stack
{
	ElemType* stk;//��̬�����ڴ棻
	int top;//����ջ����
	int capacity;//ջ��������
}Stack;

//1.��ʼ��ջ��
void StackInit(Stack* Stk);
//2.ɾ��ջ��
void StackDestory(Stack* Stk);
//3.����ջ�Ƿ�Ϊ��
bool StackEmpty(Stack Stk);
//4.����ջ�ĳ��ȣ�
int StackSize(Stack Stk);
//5.����ջ��Ԫ�أ�
void StackPop(Stack* Stk);
//6.��ջ������Ԫ�أ�
void StackPush(Stack* Stk, ElemType elem);
//7.����ջ��Ԫ�أ�
ElemType StackTop(Stack* Stk);

