#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define N 10010
//支持动态增长的栈
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;  //栈顶；
	int _capacity;  //容量；
}Stack;

//初始化栈；
void StackInit(Stack* ps);
//入栈；
void StackPush(Stack* ps, STDataType data);
//出栈；
void StackPop(Stack* ps);
//获取栈顶元素；
STDataType StackTop(Stack* ps);
//获取栈中有效元素的个数；
int StackSize(Stack* ps);
//检测栈是否为空，如果为空返回非零结果，如果不为空返回0；
int StackEmpty(Stack* ps);
//销毁栈；
void StackDestroy(Stack* ps);

bool isValid(char* s) 
{
	Stack stk;
	StackInit(&stk);
    for(int i = 0; s[i] != '\0'; i++)
    {
    	if(s[i] == '(' || s[i] == '{' || s[i] == '[')
    	{
    		StackPush(&stk, s[i]);
		}
		else
		{
			if(StackEmpty(&stk)) return false;
			
			char topElem = StackTop(&stk);
			StackPop(&stk);
			if ((s[i] == ')' && topElem != '(') || 
    		(s[i] == '}' && topElem != '{') || 
    		(s[i] == ']' && topElem != '['))
			{
				return false;
			}
		}
	}
	StackDestroy(&stk);
}

int main()
{
	char s[N];
	scanf("%s", s);
	
	if(isValid(s))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	
	return 0;
}



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
