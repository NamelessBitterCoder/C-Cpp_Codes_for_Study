#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main()
{
	Stack stk;
	StackInit(&stk);
	StackPush(&stk, 4);
	StackPush(&stk, 3);
	StackPush(&stk, 2);
	StackPush(&stk, 1);
	StackPush(&stk, 0);
	printf("压入元素后栈的长度：%d\n", StackLength(stk));
	printf("栈内元素：\n");
	while (!StackEmpty(stk))
	{
		printf("%d\n", StackTop(&stk));
		StackPop(&stk);
	}
	printf("弹出元素后栈的长度：%d\n", StackLength(stk));
	StackDelete(&stk);
	return 0;
}