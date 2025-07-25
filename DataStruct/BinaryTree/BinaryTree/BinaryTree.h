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

//3.先序遍历；
void PrevOrder(BTNode* root);

//4.中序遍历；
void InOrder(BTNode* root);

//5.后序遍历；
void PostOrder(BTNode* root);