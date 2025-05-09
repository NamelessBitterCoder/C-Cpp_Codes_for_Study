#pragma once
#include<stdio.h>
#include<assert.h>

//֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;  //ջ����
	int _capacity;  //������
}Stack;

//��ʼ��ջ��
void StackInit(Stack* ps);
//��ջ��
void StackPush(Stack* ps, STDataType data);
//��ջ��
void StackPop(Stack* ps);
//��ȡջ��Ԫ�أ�
STDataType StackTop(Stack* ps);
//��ȡջ����ЧԪ�صĸ�����
int StackSize(Stack* ps);
//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0��
int StackEmpty(Stack* ps);
//����ջ��
void StackDestroy(Stack* ps);