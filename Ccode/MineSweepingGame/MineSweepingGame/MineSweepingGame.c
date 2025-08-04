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
		for (int j = 1; j < COL - 1; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}

//3.在棋盘上布置雷的函数；
void SetMine(char a[ROW][COL])
{
	int count = EASY_COUNT;
	while (count)
	{
		//生成雷的下标范围为1 - 9；
		int x = rand() % (ROW - 2) + 1;
		int y = rans() % (COL - 2) + 1;
		for (int i = 1; i < ROW - 1; i++)
		{
			for (int j = 1; j < COL - 1; j++)
			{
				//只有成功设置雷以后，才将count减小；
				if (a[i][j] == '0')
				{
					a[i][j] = '1';
					count--;
				}
			}
		}
	}
}

//4.查找雷的函数；
void FindMine(char mine[ROW][COL],char show[ROW][COL])
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < (ROW - 2) * (COL - 2) - EASY_COUNT)
	{
		printf("请输入你要排查的坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 10 && y >= 1 && y <= 10)
		{
			if (mine[x][y] == '1')
			{
				printf("这个地方是一颗雷。\n");
				break;
			}
			else
			{
				show[x][y] = GetMine(mine, x, y);
			}
		}
	}
}

int GetMine(char a[ROW][COL], int x, int y)
{
	return a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1]
		+ a[x][y - 1] + a[x][y + 1]
		+ a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1] - 8 * '0';
}
