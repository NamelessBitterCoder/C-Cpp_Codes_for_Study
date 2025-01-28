#define _CRT_SECURE_NO_WARNINGS 1

#include"SingleList.h"

int main()
{
	SLNode* phead = SListInit();
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SListDestory(phead);
	return 0;
}