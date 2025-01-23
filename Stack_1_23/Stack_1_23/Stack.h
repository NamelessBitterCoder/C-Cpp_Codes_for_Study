#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
//�ö�̬˳���ʵ��ջ��
typedef struct Stack
{
	ElemType* stk;//��̬�����ڴ棻
	int top;//����ջ����
	int capacity;//ջ��������
}Stack;

//1.��ʼ��ջ��
void InitStack(Stack* Stk);
//2.ɾ��ջ��
void DeleteStack(Stack* Stk);
//3.����ջ�Ƿ�Ϊ��
bool StackEmpty(Stack Stk);
//4.����ջ�ĳ��ȣ�
void StackLength(Stack Stk);
//5.����ջ��Ԫ�أ�
void StackPop(Stack* Stk, ElemType elem);
//6.��ջ������Ԫ�أ�
void StackPush(Stack* Stk, ElemType elem);

