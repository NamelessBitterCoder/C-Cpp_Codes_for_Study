#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

int main()
{
	BTNode* root = CreateBinaryTree();

	printf("先序遍历：\n");
	PrevOrder(root);
	printf("\n");

	printf("中序遍历：\n");
	InOrder(root);
	printf("\n");

	printf("后序遍历：\n");
	PostOrder(root);
	printf("\n");

	printf("TreeSize: %d\n", TreeSize(root));
	printf("TreeLeafSize: %d\n", TreeLeafSize(root));
	printf("TreeHeight: %d\n", TreeHeight(root));
	return 0;
}