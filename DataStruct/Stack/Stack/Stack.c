#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//初始化栈；
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;  
	ps->_top = 0; //指向栈顶数据的下一个位置；
	ps->_capacity = 0;
}

//入栈；
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!\n");
			return;
		}
		ps->_a = tmp;
		ps->_capacity = newcapacity;
		//printf("ps->_a = %p\n", (void*)ps->_a);
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

//出栈；
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	ps->_top--;
}

//获取栈顶元素；
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_a);
	return ps->_a[ps->_top - 1];
}

//获取栈中有效元素的个数；
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

//检测栈是否为空，如果为空返回非零结果，如果不为空返回0；
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}

//销毁栈；
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}