#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 11
#define COL 11
#define EASY_COUNT 10

//1.棋盘数组的初始化函数；
void InitBoard(char a[ROW][COL],int row, int col, char ch);

//2.棋盘的打印函数；
void PrintBoard(char a[ROW][COL]);

//3.在棋盘上布置雷的函数；
void SetMine(char a[ROW][COL]);

//4.查找雷的函数；
void FindMine(char a[ROW][COL], int x, int y);
int GetMine(char a[ROW][COL], int x, int y);
