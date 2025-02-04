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
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		printf("��ʱջ��Ԫ�ظ�����%d\n", StackSize(&s));
		StackPop(&s);
	}
	printf("��ʱջ��Ԫ�ظ�����%d\n", StackSize(&s));
	StackDestroy(&s);
	return 0;
}