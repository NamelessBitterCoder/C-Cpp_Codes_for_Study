#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//1.��ʼ��ջ��
void InitStack(Stack* Stk)
{
	//��ʼ������ռ�
	ElemType* newstk = (ElemType*)realloc(newstk,4*sizeof(ElemType));
	if (newstk == NULL)
	{
		perror("Realloc Failed!");
		exit(1);
	}
	Stk->stk = newstk;
	Stk->top = 0;//��ջΪ��ʱջ��ָ��0��ջ��ָ��ջ��Ԫ�صĺ�һλ��
	Stk->capacity = 4 * sizeof(ElemType);
}

//2.ɾ��ջ��
void DeleteStack(Stack* Stk)
{
	free(Stk->stk);
	Stk->stk = NULL;
}

//3.����ջ�Ƿ�Ϊ��
bool StackEmpty(Stack Stk)
{
	return Stk.top;
}

//4.����ջ�ĳ��ȣ�
void StackLength(Stack Stk)
{
	return Stk.top;
}

//5.����ջ��Ԫ�أ�
void StackPop(Stack* Stk, ElemType elem)
{

}