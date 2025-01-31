#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* next;
	struct Node* random;
	int val;
}Node;

//申请新的节点；
Node* CreateNode(int val)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		perror("Malloc Fail!\n");
		exit(1);
	}
	newnode->next = NULL;
	newnode->random = NULL;
	newnode->val = val;
	//返回申请空间的地址；
	return newnode;
}

//添加副本节点，用于赋值随机指针；
void AddCopyNodes(Node* phead)
{
	Node* pcur = phead;
	while (pcur)
	{
		Node* copynode = CreateNode(pcur->val);
		copynode->next = pcur->next;
		pcur->next = copynode;
		//pcur往后继续走；
		pcur = pcur->next;
	}
}

Node* copyRandomList(Node* phead)
{

}