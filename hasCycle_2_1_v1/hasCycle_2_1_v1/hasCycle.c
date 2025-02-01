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
	//如果链表为空或者只有一个节点，那么一定不可能成环；
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	//定义快慢指针；
	Node* fast = head;
	Node* slow = head;
	//进环以后fast指针和slow指针没走一步，距离缩短 1 个节点；
	while(fast&&fast->next)
	{
		fast = fast->next->next;//fast指针每次走 2 步；
		slow = slow->next;//slow指针每次走 1 步；
		if (fast == slow)//如果两个指针相遇，那么只能是在环内相遇；
		{
			return true;
		}
	}
	//如果快慢指针在整个循环的过程中都没有相遇，那么链表就不带环；
	return false;
}