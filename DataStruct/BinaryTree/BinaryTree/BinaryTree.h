#pragma once
#include<stdio.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//1.创建节点；
BTNode* BuyNode(int x);

//2.创建二叉树；
BTNode* CreateBinaryTree();