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
		printf("��ͷԪ��Ϊ��%d  ��βԪ��Ϊ��%d  ", QueueFront(&q1),QueueBack(&q1));
		printf("��ʱ���еĳ���Ϊ��%d\n", QueueSize(&q1));
		QueuePop(&q1);
	}
	printf("ɾ����ϣ���ʱ���еĳ���Ϊ��%d\n", QueueSize(&q1));
	QueueDestroy(&q1);
	return 0;
}