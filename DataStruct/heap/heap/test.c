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
	HeapDestroy(&hp);
}

int main()
{
	test1();
	return 0;
}