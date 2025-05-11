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
    //�������Ϊ�ջ���ֻ��һ���ڵ㣬��ô�Ͳ������л�������null��
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    //�������ָ�룻
    Node* fast = head;
    Node* slow = head;

    while (fast && fast->next)
    {
        //��ָ��ÿ��ͷ��������ָ��ÿ����һ����
        fast = fast->next->next;
        slow = slow->next;
        //��������ʱ��������ָ��ָ��ͷ��
        if (fast == slow)
        {
            slow = head;
            break;
        }
    }
    //����ָ�뱣��ͬ�����ٶȣ��ٴ�����ʱ�Ľڵ���ǻ�����ڣ�
    while (fast)
    {
        //�����ж����ڴ���ֻ�������ڵ��γɵĻ������ú�����ָ�붼ָ��ͷ�ڵ㣻
        if (fast == slow)
        {
            return fast;
        }
        fast = fast->next;
        slow = slow->next;
    }
    //���û�������������ͷ���null��
    return NULL;
}