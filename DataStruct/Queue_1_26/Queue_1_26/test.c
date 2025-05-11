#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

int main()
{
	Que qu;
	QueueInit(&qu);
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	QueuePush(&qu, 4);
	while(!QueueEmpty(&qu))
	{
		printf("%d ", QueueFront(&qu));
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 0;
}