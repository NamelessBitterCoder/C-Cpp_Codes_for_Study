#define _CRT_SECURE_NO_WARNINGS
#include"MineSweepingGame.h"

int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		menu();
		printf("��ѡ��>");
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			input = 0;
			break;
		default:
			printf("ѡ��������������룡\n");
			break;
		}
		if (input == 0)
		{
			break;
		}
	}
	return 0;
}