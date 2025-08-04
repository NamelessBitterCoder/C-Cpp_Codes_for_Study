#define _CRT_SECURE_NO_WARNINGS
#include"MineSweepingGame.h"

int main()
{
	char mine[ROW][COL];
	char show[ROW][COL];
	InitBoard(mine, ROW, COL, '0');
	InitBoard(show, ROW, COL, '*');
	//PrintBoard(mine);
	PrintBoard(show);
	return 0;
}