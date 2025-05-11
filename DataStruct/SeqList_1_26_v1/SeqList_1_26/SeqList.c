#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//1.顺序表的初始化；
void SeqListInit(SL* sl)
{
	sl->a = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

//2.顺序表的销毁；
void SeqListDestory(SL* sl)
{
	assert(sl);
	free(sl->a);
	sl->a = NULL;
}

//3.顺序表的头插；
void SeqListPushFront(SL* sl, DataType elem)
{
	assert(sl);
	//如果空间不足，就申请空间；
	if (sl->capacity == sl->size)
	{
		int newcapacity = sl->capacity == 0 ? 1 : sl->capacity * 2;
		DataType* new = (DataType*)realloc(sl->a, newcapacity * sizeof(DataType));
		//如果申请空间失败，就退出程序；
		if (new == NULL)
		{
			perror("Realloc Fail!\n");
			exit(1);
		}
		//如果申请空间成功，就指向新的空间；
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

//4.顺序表的尾插；
void SeqListPushBack(SL* sl, DataType elem)
{
	assert(sl);
	//如果空间不足，就申请空间；
	if (sl->capacity == sl->size)
	{
		int newcapacity = sl->capacity == 0 ? 1 : sl->capacity * 2;
		DataType* new = (DataType*)realloc(sl->a, newcapacity * sizeof(DataType));
		//如果申请空间失败，就退出程序；
		if (new == NULL)
		{
			perror("Realloc Fail!\n");
			exit(1);
		}
		//如果申请空间成功，就指向新的空间；
		sl->a = new;
		sl->capacity = newcapacity;

	}
	//在最后一位插入；
	sl->a[sl->size] = elem;
	sl->size++;
}

//5.顺序表的头删；
void SeqListDeleteFront(SL* sl)
{
	assert(sl);
	//整体前移一位，覆盖首元素；
	for (int i = 0; i < sl->size-1; i++)
	{
		sl->a[i] = sl->a[i + 1];
	}
	sl->size--;
}

//6.顺序表的尾删；
void SeqListDeleteBack(SL* sl)
{
	assert(sl);
	sl->size--;
}

//7.查找顺序表中是否存在值为elem的元素；
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
	
	//如果没有找到，就返回-1；
	return -1;
}

//8.删除满足给定的值的元素，返回对应元素的下标；
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

		//顺序表中不包含值为elem的元素；
		return false;
	}
}

//9.打印顺序表；
void SeqListPrint(SL* sl)
{
	assert(sl);
	if (sl->size == 0)
	{
		printf("顺序表内没有元素！");
	}
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->a[i]);
	}
}