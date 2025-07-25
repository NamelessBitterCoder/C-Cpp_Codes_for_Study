#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//1.创建节点；
BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fali");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;
}

//2.创建二叉树；
BTNode* CreateBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

//3.先序遍历；
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//4.中序遍历；
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//5.后序遍历；
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	PostOredr(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}