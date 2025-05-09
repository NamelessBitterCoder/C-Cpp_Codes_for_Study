#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//��ʼ��ջ��
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;  
	ps->_top = 0; //ָ��ջ�����ݵ���һ��λ�ã�
	ps->_capacity = 0;
}

//��ջ��
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

//��ջ��
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	ps->_top--;
}

//��ȡջ��Ԫ�أ�
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_a);
	return ps->_a[ps->_top - 1];
}

//��ȡջ����ЧԪ�صĸ�����
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0��
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}

//����ջ��
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}