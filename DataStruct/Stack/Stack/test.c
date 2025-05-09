#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	while (!StackEmpty(&s))
	{
		printf("%d\n", StackTop(&s));
		StackPop(&s);
	}
	StackDestroy(&s);
	return 0;
}