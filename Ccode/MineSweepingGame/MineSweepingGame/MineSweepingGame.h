#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 11
#define COL 11
#define EASY_COUNT 10

//1.��������ĳ�ʼ��������
void InitBoard(char a[ROW][COL],int row, int col, char ch);

//2.���̵Ĵ�ӡ������
void PrintBoard(char a[ROW][COL]);

//3.�������ϲ����׵ĺ�����
void SetMine(char a[ROW][COL]);

//4.�����׵ĺ�����
void FindMine(char a[ROW][COL], int x, int y);
int GetMine(char a[ROW][COL], int x, int y);
