#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出较小的的那个孩子；
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapPush(HP* php, HPDataType val)
{
	assert(php);
	//如果空间不足，则申请新的空间；
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		php->a = tmp;
		php->capacity = newcapacity;
	}
	
	php->a[php->size] = val;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size - 1, 0);
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}