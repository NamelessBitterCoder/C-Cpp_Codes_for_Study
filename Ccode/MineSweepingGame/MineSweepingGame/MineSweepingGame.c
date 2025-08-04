#define _CRT_SECURE_NO_WARNINGS
#include"MineSweepingGame.h"

void InitBoard(char a[ROW][COL], int row, int col, char ch)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = ch;
		}
	}
}

void PrintBoard(char a[ROW][COL])
{
	for (int i = 1; i < ROW - 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i < ROW - 1; i++)
	{
		for (int j = 1; j < COL - 1; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}

//3.�������ϲ����׵ĺ�����
void SetMine(char a[ROW][COL])
{
	int count = EASY_COUNT;
	while (count)
	{
		//�����׵��±귶ΧΪ1 - 9��
		int x = rand() % (ROW - 2) + 1;
		int y = rand() % (COL - 2) + 1;
		//ֻ�гɹ��������Ժ󣬲Ž�count��С��
		if (a[x][y] == '0')
		{
			a[x][y] = '1';
			count--;
		}
	}
}

//4.�����׵ĺ�����
void FindMine(char mine[ROW][COL],char show[ROW][COL])
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < (ROW - 2) * (COL - 2) - EASY_COUNT)
	{
		printf("��������Ҫ�Ų�����꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 10 && y >= 1 && y <= 10)
		{
			if (mine[x][y] == '1')
			{
				printf("����ط���һ����, ��Ϸ������\n");
				break;
			}
			else
			{
				show[x][y] = GetMine(mine, x, y) + '0';
				PrintBoard(show);
				win++;
				continue;
			}
		}
		else
		{
			printf("������ǷǷ����꣬���������룡\n");
			continue;
		}
	}
	if (win == (ROW - 2) * (COL - 2) - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		PrintBoard(show);
	}
}

int GetMine(char a[ROW][COL], int x, int y)
{
	return a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1]
		+ a[x][y - 1] + a[x][y + 1]
		+ a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1] - 8 * '0';
}

//5.��Ϸ�߼�������
void game()
{
	char mine[ROW][COL];
	char show[ROW][COL];

	InitBoard(mine, ROW, COL, '0');
	InitBoard(show, ROW, COL, '*');

	PrintBoard(show);

	SetMine(mine);

	FindMine(mine, show);
}

//6.��Ϸ�˵���
void menu()
{
	printf("*************************\n");
	printf("******** 1. play ********\n");
	printf("******** 0. exit ********\n");
	printf("*************************\n");
}
