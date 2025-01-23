#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//1.初始化栈；
void InitStack(Stack* Stk)
{
	//初始化申请空间
	ElemType* newstk = (ElemType*)realloc(newstk,4*sizeof(ElemType));
	if (newstk == NULL)
	{
		perror("Realloc Failed!");
		exit(1);
	}
	Stk->stk = newstk;
	Stk->top = 0;//当栈为空时栈顶指向0，栈顶指向栈顶元素的后一位。
	Stk->capacity = 4 * sizeof(ElemType);
}

//2.删除栈；
void DeleteStack(Stack* Stk)
{
	free(Stk->stk);
	Stk->stk = NULL;
}

//3.检验栈是否为空
bool StackEmpty(Stack Stk)
{
	return Stk.top;
}

//4.返回栈的长度；
void StackLength(Stack Stk)
{
	return Stk.top;
}

//5.弹出栈顶元素；
void StackPop(Stack* Stk, ElemType elem)
{

}