#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int money = 20;
	int bottles = 0;
	int emptybottles = 0;
	int totaldrinks = 0;

	bottles = money;
	totaldrinks += bottles;
	
	while (bottles>0)
	{
		emptybottles += bottles;//先计算空瓶的数量；
		bottles = emptybottles / 2;//再计算现有的空瓶可以换到多少瓶可乐；
		emptybottles = emptybottles % 2;//换完后还剩下一个空瓶子。
		totaldrinks += bottles;//记录新换来喝的可乐；

	}

	printf("%d", totaldrinks);

	return 0;
}