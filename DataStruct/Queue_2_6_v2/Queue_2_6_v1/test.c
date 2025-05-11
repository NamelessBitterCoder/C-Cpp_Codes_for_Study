#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

int main()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	while (!QueueEmpty(&q1))
	{
		printf("队头元素为：%d  队尾元素为：%d  ", QueueFront(&q1),QueueBack(&q1));
		printf("此时队列的长度为：%d\n", QueueSize(&q1));
		QueuePop(&q1);
	}
	printf("删除完毕，此时队列的长度为：%d\n", QueueSize(&q1));
	QueueDestroy(&q1);
	return 0;
}