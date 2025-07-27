#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

//1.�����ڵ㣻
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

//2.������������
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

//3.���������
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

//4.���������
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

//5.���������
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

//6.�������ڵ����Ŀ��
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeLeafSize(root->left) + TreeLeafSize(root->right) + 1;
}

//7.������Ҷ�ӽڵ����Ŀ��
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//8.�������ĸ߶ȣ�
int TreeHeight(BTNode* root)
{
	//�ȿ���Ϊ�յ������
	if (root == NULL)
		return 0;

	//�������ĸ߶��൱�����������������ĸ߶ȵĽϴ�ֵ + 1��
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//��Ч�����⣻
/*
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	return TreeHeight(root->left) > TreeHeight(root->right) ?
		TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
}
*/