#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* next;
	struct Node* random;
	int val;
}Node;

//�����µĽڵ㣻
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
	//��������ռ�ĵ�ַ��
	return newnode;
}

//��Ӹ����ڵ㣬���ڸ�ֵ���ָ�룻
void AddCopyNodes(Node* phead)
{
	Node* pcur = phead;
	while (pcur)
	{
		Node* copynode = CreateNode(pcur->val);
		copynode->next = pcur->next;
		pcur->next = copynode;
		//pcur��������ߣ�
		pcur = pcur->next;
	}
}

Node* copyRandomList(Node* phead)
{

}