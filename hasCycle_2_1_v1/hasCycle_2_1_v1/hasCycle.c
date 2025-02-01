#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode
{
	struct ListNode* next;
	int val;
}Node;

bool hasCycle(Node* head)
{
	//�������Ϊ�ջ���ֻ��һ���ڵ㣬��ôһ�������ܳɻ���
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	//�������ָ�룻
	Node* fast = head;
	Node* slow = head;
	//�����Ժ�fastָ���slowָ��û��һ������������ 1 ���ڵ㣻
	while(fast&&fast->next)
	{
		fast = fast->next->next;//fastָ��ÿ���� 2 ����
		slow = slow->next;//slowָ��ÿ���� 1 ����
		if (fast == slow)//�������ָ����������ôֻ�����ڻ���������
		{
			return true;
		}
	}
	//�������ָ��������ѭ���Ĺ����ж�û����������ô����Ͳ�������
	return false;
}