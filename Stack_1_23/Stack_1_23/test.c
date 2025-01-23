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
	printf("ѹ��Ԫ�غ�ջ�ĳ��ȣ�%d\n", StackLength(stk));
	printf("ջ��Ԫ�أ�\n");
	while (!StackEmpty(stk))
	{
		printf("%d\n", StackTop(&stk));
		StackPop(&stk);
	}
	printf("����Ԫ�غ�ջ�ĳ��ȣ�%d\n", StackLength(stk));
	StackDelete(&stk);
	return 0;
}