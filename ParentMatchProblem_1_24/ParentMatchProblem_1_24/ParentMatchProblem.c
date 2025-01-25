#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

bool isMatched(char* pc)
{
	assert(*pc);
	Stack stk;
	StackInit(&stk);
	while (*pc)
	{
		if (*pc == '(' || *pc == '[' || *pc == '{')
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
			if (top == '(' && *pc == ']' || top == '(' && *pc == '}'
				|| top == '[' && *pc == ')' || top == '[' && *pc == '}'
				|| top == '{' && *pc == ']' || top == '{' && *pc == ')')
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
	char* parents = "(())[]{}";
	char* print = parents;
	printf("需要匹配的字符串：\n");
	while (*print)
	{
		printf("%c ", *print);
		print++;
	}
	printf("\n");
	printf("输入的括号字符串的匹配结果：\n");
	if (isMatched(parents))
	{
		printf("匹配成功！\n");
	}
	else
	{
		printf("匹配失败！\n");
	}
	return 0;
}