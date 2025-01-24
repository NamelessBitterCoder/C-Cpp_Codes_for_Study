#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

bool isMatched(char* pc)
{
	Stack stk;
	StackInit(&stk);
	while (*pc)
	{
		if (*pc == "(" || *pc == "[" || *pc == "{")
		{
			StackPush(&stk, *pc);
		}
		else
		{
			if (StackEmpty(stk))
			{
				StackDestory(&stk);
				return false;
			}
			char top=StackTop(&stk);
			StackPop(&stk);
			if (top == "(" && *pc == "]" || top == "(" && *pc == "}"
				|| top == "[" && *pc == ")" || top == "[" && *pc == "}"
				|| top == "{" && *pc == "]" || top == "{" && *pc == ")")
			{
				StackDestory(&stk);
				return false;
			}
		}
		pc++;
	}
	int empty = StackEmpty(stk);
	StackDestory(&stk);
	if (!empty)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	char* parents = "(()){}[]";
	printf("��Ҫƥ����ַ�����\n");
	while (*parents)
	{
		printf("%c ", *parents);
		parents++;
	}
	printf("\n");
	printf("����������ַ�����ƥ������\n");
	if (isMatched(&parents))
	{
		printf("ƥ��ɹ���\n");
	}
	else
	{
		printf("ƥ��ʧ�ܣ�\n");
	}
	return 0;
}