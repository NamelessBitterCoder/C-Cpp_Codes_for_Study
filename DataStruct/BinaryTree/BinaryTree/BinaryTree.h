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