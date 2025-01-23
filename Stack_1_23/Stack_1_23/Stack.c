#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//1.��ʼ��ջ��
void StackInit(Stack* Stk)
{
	//��ʼ������ռ�
	ElemType* newstk = (ElemType*)malloc(4 * sizeof(ElemType));
	if (newstk == NULL)
	{
		perror("Realloc Failed!");
		exit(1);
	}
	Stk->stk = newstk;
	Stk->top = 0;//��ջΪ��ʱջ��ָ��0��ջ��ָ��ջ��Ԫ�صĺ�һλ��
	Stk->capacity = 4 ;
}

//2.ɾ��ջ��
void StackDelete(Stack* Stk)
{
	assert(Stk);
	assert(Stk->stk);
	free(Stk->stk);
	Stk->stk = NULL;
	Stk->top = 0;
	Stk->capacity = 0;
}

//3.����ջ�Ƿ�Ϊ��
bool StackEmpty(Stack Stk)
{
	return Stk.top == 0;
}

//4.����ջ�ĳ��ȣ�
int StackLength(Stack Stk)
{
	return Stk.top;
}

//5.����ջ��Ԫ�أ�
void StackPop(Stack* Stk)
{
	assert(Stk);
	assert(!StackEmpty(*Stk)); // ȷ��ջ��Ϊ��
	Stk->top--;
}

//6.��ջ������Ԫ�أ�
void StackPush(Stack* Stk, ElemType elem)
{
	assert(Stk);
	if (Stk->top == Stk->capacity) {
		int newcapacity = Stk->capacity * 2;
		ElemType* newstk = (ElemType*)realloc(Stk->stk, newcapacity * sizeof(ElemType));
		if (newstk == NULL) {
			perror("Realloc Failed!");
			exit(1);
		}
		Stk->stk = newstk;
		Stk->capacity = newcapacity;
	}
	Stk->stk[Stk->top] = elem;
	Stk->top++;
}

//7.����ջ��Ԫ�أ�
ElemType StackTop(Stack* Stk)
{
	assert(Stk);
	assert(!StackEmpty(*Stk)); // ȷ��ջ��Ϊ��
	return Stk->stk[Stk->top - 1];
}