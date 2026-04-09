#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node* next;
	struct Node* random;
	int val;
};
typedef struct Node Node;
//申请新的节点；
Node* CreateNode(int val)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->next = NULL;
	newnode->random = NULL;
	newnode->val = val;
	//返回申请空间的地址；
	return newnode;
}

//添加副本节点，用于赋值随机指针；
void AddCopyNodes(Node* head)
{
	Node* pcur = head;
	while (pcur)
	{
		Node* copynode = CreateNode(pcur->val);
		copynode->next = pcur->next;
		pcur->next = copynode;
		//pcur往后继续走；
		pcur = copynode->next;
	}
}

Node* copyRandomList(Node* head)
{
	//如果传入的链表为空，则返回NULL；
	if (head == NULL)
	{
		return NULL;
	}

	AddCopyNodes(head);
	
	//先复制随机指针；
	Node* pcur = head;
	while (pcur)
	{
		if (pcur->random != NULL)
		{
			pcur->next->random = pcur->random->next;
		}
		pcur = pcur->next->next;
	}

	//再复制链表的尾指针，将副本节点摘取下来；
	Node* newnode = head->next;
	pcur = head;  //遍历指针重新指向链表的头结点；
	while (pcur)
	{
		//还原next指针；
		Node* copynode = pcur->next;//当前的副本节点
		pcur->next = copynode->next;
		//复制next指针；
		if (copynode->next != NULL)
		{
			copynode->next = copynode->next->next;
		}
		//pcur继续往后走；
		pcur = pcur->next;
	}
	//返回新的头节点的地址；
	return newnode;
}