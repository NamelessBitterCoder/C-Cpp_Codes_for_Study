#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	struct ListNode* next;
	int val;
}Node;

struct ListNode* detectCycle(struct ListNode* head)
{
    //如果链表为空或者只有一个节点，那么就不可能有环，返回null；
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    //定义快慢指针；
    Node* fast = head;
    Node* slow = head;

    while (fast && fast->next)
    {
        //快指针每次头两步，慢指针每次走一步；
        fast = fast->next->next;
        slow = slow->next;
        //两者相遇时，重置慢指针指向头；
        if (fast == slow)
        {
            slow = head;
            break;
        }
    }
    //两个指针保持同样的速度，再次相遇时的节点就是换的入口；
    while (fast)
    {
        //条件判断用于处理只有两个节点形成的环，重置后两个指针都指向头节点；
        if (fast == slow)
        {
            return fast;
        }
        fast = fast->next;
        slow = slow->next;
    }
    //如果没有满足条件，就返回null；
    return NULL;
}