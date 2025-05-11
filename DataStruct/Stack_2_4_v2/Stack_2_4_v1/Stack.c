#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//1.初始化栈；
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;  //栈顶指针指向栈顶元素的后一个；
	ps->capacity = 0;
}

//2.入栈；
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	
	if (ps->top == ps->capacity)  //如果容量不足，则申请新的空间；
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* new = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (new == NULL)
		{
			perror("Realloc Fail!\n");
			exit(1);
		}
		ps->a = new;
		ps->capacity = newcapacity;
	}
	//向栈顶插入元素；
	ps->a[ps->top] = data;
	ps->top++;
}

//3.出栈；
void StackPop(Stack* ps)
{
	assert(ps);
	ps->top--;
}

//4.获取栈顶元素；
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];  //栈顶指针指向栈顶元素的后一位；
}

//5.获取栈中元素的个数；
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;  //栈顶指针指向栈顶元素的后一位；
}

//6.检测栈是否为空，如果为空返回非零结果，如果不为空返回0；
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

//7.销毁栈；
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}