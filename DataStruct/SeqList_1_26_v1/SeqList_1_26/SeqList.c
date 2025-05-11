#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//1.˳���ĳ�ʼ����
void SeqListInit(SL* sl)
{
	sl->a = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

//2.˳�������٣�
void SeqListDestory(SL* sl)
{
	assert(sl);
	free(sl->a);
	sl->a = NULL;
}

//3.˳����ͷ�壻
void SeqListPushFront(SL* sl, DataType elem)
{
	assert(sl);
	//����ռ䲻�㣬������ռ䣻
	if (sl->capacity == sl->size)
	{
		int newcapacity = sl->capacity == 0 ? 1 : sl->capacity * 2;
		DataType* new = (DataType*)realloc(sl->a, newcapacity * sizeof(DataType));
		//�������ռ�ʧ�ܣ����˳�����
		if (new == NULL)
		{
			perror("Realloc Fail!\n");
			exit(1);
		}
		//�������ռ�ɹ�����ָ���µĿռ䣻
		sl->a = new;
		sl->capacity = newcapacity;
	}

	if (sl->size == 0)
	{
		sl->a[0] = elem;
	}
	else
	{
		for (int i = sl->size; i > 0; i--)
		{
			sl->a[i] = sl->a[i - 1];
		}
		sl->a[0] = elem;
	}
	sl->size++;

	
}

//4.˳����β�壻
void SeqListPushBack(SL* sl, DataType elem)
{
	assert(sl);
	//����ռ䲻�㣬������ռ䣻
	if (sl->capacity == sl->size)
	{
		int newcapacity = sl->capacity == 0 ? 1 : sl->capacity * 2;
		DataType* new = (DataType*)realloc(sl->a, newcapacity * sizeof(DataType));
		//�������ռ�ʧ�ܣ����˳�����
		if (new == NULL)
		{
			perror("Realloc Fail!\n");
			exit(1);
		}
		//�������ռ�ɹ�����ָ���µĿռ䣻
		sl->a = new;
		sl->capacity = newcapacity;

	}
	//�����һλ���룻
	sl->a[sl->size] = elem;
	sl->size++;
}

//5.˳����ͷɾ��
void SeqListDeleteFront(SL* sl)
{
	assert(sl);
	//����ǰ��һλ��������Ԫ�أ�
	for (int i = 0; i < sl->size-1; i++)
	{
		sl->a[i] = sl->a[i + 1];
	}
	sl->size--;
}

//6.˳����βɾ��
void SeqListDeleteBack(SL* sl)
{
	assert(sl);
	sl->size--;
}

//7.����˳������Ƿ����ֵΪelem��Ԫ�أ�
int SeqListFindValue(SL* sl, DataType elem)
{
	assert(sl);
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->a[i] == elem)
		{
			return i;
		}
	}
	
	//���û���ҵ����ͷ���-1��
	return -1;
}

//8.ɾ�����������ֵ��Ԫ�أ����ض�ӦԪ�ص��±ꣻ
bool SeqListEreaseValue(SL* sl, DataType elem)
{
	assert(sl);
	if (sl->a[0] == elem)
	{
		sl->size--;
		return true;
	}
	else
	{
		for (int i = 0; i < sl->size; i++)
		{
			if (sl->a[i] == elem)
			{
				for (int j = i; j < sl->size - 1; j++)
				{
					sl->a[j] = sl->a[j + 1];
					sl->size--;
					return true;
				}
			}
		}

		//˳����в�����ֵΪelem��Ԫ�أ�
		return false;
	}
}

//9.��ӡ˳���
void SeqListPrint(SL* sl)
{
	assert(sl);
	if (sl->size == 0)
	{
		printf("˳�����û��Ԫ�أ�");
	}
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->a[i]);
	}
}