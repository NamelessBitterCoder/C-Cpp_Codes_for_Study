#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	//1.测试尾插函数；
	/*printf("测试尾插函数：\n");
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPrint(&s1);
	printf("\n");*/

	//2.测试尾删函数；
	/*printf("测试尾删函数：\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");
	SeqListDeleteBack(&s1);
	SeqListPrint(&s1);
	printf("\n");

	SeqListDestory(&s1);*/

	//3.测试头插函数；
	/*printf("测试头插函数：\n");
	SL s2;
	SeqListInit(&s2);
	SeqListPushFront(&s2, 1);
	SeqListPrint(&s2);
	printf("\n");
	SeqListPushFront(&s2, 2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListPushFront(&s2, 3);
	SeqListPrint(&s2);
	printf("\n");
	SeqListPushFront(&s2, 4);
	SeqListPrint(&s2);
	printf("\n");*/

	//4.测试头删函数；
	/*printf("测试头删函数：\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");
	SeqListDeleteFront(&s2);
	SeqListPrint(&s2);
	printf("\n");

	SeqListDestory(&s2);*/

	//5.测试查找指定值的元素；
	SL s3;
	SeqListInit(&s3);
	SeqListPushBack(&s3, 1);
	SeqListPushBack(&s3, 2);
	SeqListPushBack(&s3, 3);
	SeqListPushBack(&s3, 4);
	SeqListPrint(&s3);
	printf("\n");
	
	//找到指定值的元素；
	int x = 3;
	printf("在顺序表中查找值为%d的元素：",x);
	int find = SeqListFindValue(&s3, x);
	if (find >= 0)
	{
		printf("找到了，对应元素的下标为：%d\n", find);
	}
	else
	{
		printf("没有找到对应的元素！\n");
	}

	//6.测试删除指定值的元素；
	printf("删除值为%d的元素：",x);
	int ret= SeqListEreaseValue(&s3, x);
	if (ret)
	{
		printf("删除成功！\n");
	}
	else
	{
		printf("删除失败！\n");
	}

	SeqListDestory(&s3);

	return 0;
}