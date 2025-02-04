#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//1.��ʼ��ջ��
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;  //ջ��ָ��ָ��ջ��Ԫ�صĺ�һ����
	ps->capacity = 0;
}

//2.��ջ��
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	
	if (ps->top == ps->capacity)  //����������㣬�������µĿռ䣻
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
	//��ջ������Ԫ�أ�
	ps->a[ps->top] = data;
	ps->top++;
}

//3.��ջ��
void StackPop(Stack* ps)
{
	assert(ps);
	ps->top--;
}

//4.��ȡջ��Ԫ�أ�
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];  //ջ��ָ��ָ��ջ��Ԫ�صĺ�һλ��
}

//5.��ȡջ��Ԫ�صĸ�����
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;  //ջ��ָ��ָ��ջ��Ԫ�صĺ�һλ��
}

//6.���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0��
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

//7.����ջ��
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}