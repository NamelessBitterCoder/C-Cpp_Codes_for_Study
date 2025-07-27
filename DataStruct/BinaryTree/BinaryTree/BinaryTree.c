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

//6.二叉树节点的数目；
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeLeafSize(root->left) + TreeLeafSize(root->right) + 1;
}

//7.二叉树叶子节点的数目；
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//8.二叉树的高度；
int TreeHeight(BTNode* root)
{
	//先考虑为空的情况；
	if (root == NULL)
		return 0;

	//二叉树的高度相当于左子树和右子树的高度的较大值 + 1；
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//有效率问题；
/*
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	return TreeHeight(root->left) > TreeHeight(root->right) ?
		TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
}
*/