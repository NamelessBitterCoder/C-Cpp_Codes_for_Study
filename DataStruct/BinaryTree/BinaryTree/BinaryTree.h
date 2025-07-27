#pragma once
#include<stdio.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//1.�����ڵ㣻
BTNode* BuyNode(int x);

//2.������������
BTNode* CreateBinaryTree();

//3.���������
void PrevOrder(BTNode* root);

//4.���������
void InOrder(BTNode* root);

//5.���������
void PostOrder(BTNode* root);

//6.�������ڵ����Ŀ��
int TreeSize(BTNode* root);

//7.������Ҷ�ӽڵ����Ŀ��
int TreeLeafSize(BTNode* root);

//8.�������ĸ߶ȣ�
int TreeHeight(BTNode* root);