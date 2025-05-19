#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define N 10010
//֧�ֶ�̬������ջ
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;  //ջ����
	int _capacity;  //������
}Stack;

//��ʼ��ջ��
void StackInit(Stack* ps);
//��ջ��
void StackPush(Stack* ps, STDataType data);
//��ջ��
void StackPop(Stack* ps);
//��ȡջ��Ԫ�أ�
STDataType StackTop(Stack* ps);
//��ȡջ����ЧԪ�صĸ�����
int StackSize(Stack* ps);
//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0��
int StackEmpty(Stack* ps);
//����ջ��
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
