#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//1.初始化栈；
void StackInit(Stack* Stk)
{
	//初始化申请空间
	ElemType* newstk = (ElemType*)malloc(4 * sizeof(ElemType));
	if (newstk == NULL)
	{
		perror("Realloc Failed!");
		exit(1);
	}
	Stk->stk = newstk;
	Stk->top = 0;//当栈为空时栈顶指向0，栈顶指向栈顶元素的后一位。
	Stk->capacity = 4 ;
}

//2.删除栈；
void StackDelete(Stack* Stk)
{
	assert(Stk);
	assert(Stk->stk);
	free(Stk->stk);
	Stk->stk = NULL;
	Stk->top = 0;
	Stk->capacity = 0;
}

//3.检验栈是否为空
bool StackEmpty(Stack Stk)
{
	return Stk.top == 0;
}

//4.返回栈的长度；
int StackLength(Stack Stk)
{
	return Stk.top;
}

//5.弹出栈顶元素；
void StackPop(Stack* Stk)
{
	assert(Stk);
	assert(!StackEmpty(*Stk)); // 确保栈不为空
	Stk->top--;
}

//6.向栈顶插入元素；
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

//7.访问栈顶元素；
ElemType StackTop(Stack* Stk)
{
	assert(Stk);
	assert(!StackEmpty(*Stk)); // 确保栈不为空
	return Stk->stk[Stk->top - 1];
}