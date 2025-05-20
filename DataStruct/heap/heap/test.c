#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test1()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 1, 3, 4, 2, 7, 8, 9 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HeapDestroy(&hp);
}

void HeapSort(int* a, int length)
{
	for (int i = 1; i < length; i++)
	{
		AdjustUp(a, i);
	}

	int end = length - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
int main()
{
	//test1();
	int a[] = { 1, 12, 23, 14, 5, 26, 55, 41, 82, 10, 23 };
	int len = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
	HeapSort(a, len);
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	return 0;
}