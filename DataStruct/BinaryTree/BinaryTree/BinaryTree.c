#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

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