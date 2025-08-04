#define _CRT_SECURE_NO_WARNINGS
#include"MineSweepingGame.h"

int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		menu();
		printf("请选择>");
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			input = 0;
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}
		if (input == 0)
		{
			break;
		}
	}
	return 0;
}