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
//�����µĽڵ㣻
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
	//��������ռ�ĵ�ַ��
	return newnode;
}

//��Ӹ����ڵ㣬���ڸ�ֵ���ָ�룻
void AddCopyNodes(Node* head)
{
	Node* pcur = head;
	while (pcur)
	{
		Node* copynode = CreateNode(pcur->val);
		copynode->next = pcur->next;
		pcur->next = copynode;
		//pcur��������ߣ�
		pcur = copynode->next;
	}
}

Node* copyRandomList(Node* head)
{
	//������������Ϊ�գ��򷵻�NULL��
	if (head == NULL)
	{
		return NULL;
	}

	AddCopyNodes(head);
	
	//�ȸ������ָ�룻
	Node* pcur = head;
	while (pcur)
	{
		if (pcur->random != NULL)
		{
			pcur->next->random = pcur->random->next;
		}
		pcur = pcur->next->next;
	}

	//�ٸ��������βָ�룬�������ڵ�ժȡ������
	Node* newnode = head->next;
	pcur = head;  //����ָ������ָ�������ͷ��㣻
	while (pcur)
	{
		//��ԭnextָ�룻
		Node* copynode = pcur->next;//��ǰ�ĸ����ڵ�
		pcur->next = copynode->next;
		//����nextָ�룻
		if (copynode->next != NULL)
		{
			copynode->next = copynode->next->next;
		}
		//pcur���������ߣ�
		pcur = pcur->next;
	}
	//�����µ�ͷ�ڵ�ĵ�ַ��
	return newnode;
}