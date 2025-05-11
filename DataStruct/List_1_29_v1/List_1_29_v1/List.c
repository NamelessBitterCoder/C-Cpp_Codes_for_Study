#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//1.��ʼ��˫������
void ListInit(List* L)
{
	//Ϊ�ڱ��ڵ�����ռ䣻
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		perror("Malloc Fail!\n");
		exit(1);
	}
	Node* tail = (Node*)malloc(sizeof(Node));
	if (tail == NULL)
	{
		perror("Malloc Fail!\n");
		exit(1);
	}
	//��ʼ���ڱ��ڵ㣻
	L->head = head;
	L->head->succ = tail;
	L->head->pred = NULL;

	L->tail = tail;
	L->tail->succ = NULL;
	L->tail->pred = head;
}

//2.����˫������
void ListDestroy(List* L)
{
	assert(L);//ȷ�������ָ����Ч��
	Node* pcur = L->head;//��ͷ��㿪ʼ��
	while (pcur)
	{
		Node* next = pcur->succ;//��¼��һ���ڵ㣻
		free(pcur);//ɾ�����½ڵ㣻
		pcur = next;//���½ڵ㣻
	}

	// �������ͷָ���βָ����Ϊ�գ���������ָ��;
	L->head = NULL;
	L->tail = NULL;
}

//3.˫�����������µĽڵ㣻
Node* CreateNode(DataType elem)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		perror("Malloc Fail!\n");
		exit(1);
	}
	newnode->val = elem;
	newnode->pred = NULL;
	newnode->succ = NULL;
}

//4.˫�������ͷ�壻
void ListPushFront(List* L, DataType elem)
{
	assert(L);
	//�����µĽڵ㣻
	Node* newnode = CreateNode(elem);
	//�޸�ָ���ָ��
	newnode->succ = L->head->succ;
	newnode->pred = L->head;
	newnode->succ->pred = newnode;
	L->head->succ = newnode;
}

//5.˫�������β�壻
void ListPushBack(List* L, DataType elem)
{
	assert(L);
	//�����µĽڵ㣻
	Node* newnode = CreateNode(elem);
	//�޸�ָ���ָ��
	newnode->pred = L->tail->pred;
	newnode->succ = L->tail;
	newnode->pred->succ = newnode;
	L->tail->pred = newnode;

}

//6.˫������Ĵ�ӡ������
void ListPrint(List* L)
{
	assert(L);
	//��ָ�������
	Node* pcur = L->head->succ;
	while (pcur != L->tail)
	{
		printf("%d - ", pcur->val);
		pcur = pcur->succ;
	}
	printf("\n");
}

//7.˫�������ͷɾ������
void ListPopFront(List* L)
{
	assert(L);
	//��¼ͷ�ڱ��ڵ����һ���ڵ㣻
	Node* deletenode = L->head->succ;
	deletenode->succ->pred = L->head;
	L->head->succ = deletenode->succ;
	free(deletenode);
}

//8.˫�������βɾ������
void ListPopBack(List* L)
{
	assert(L);
	//��¼β�ڱ��ڵ��ǰһ���ڵ㣻
	Node* deletenode = L->tail->pred;
	deletenode->pred->succ = L->tail;
	L->tail->pred = deletenode->pred;
	free(deletenode);
}

//9.��������Ѱ��ֵΪelem�Ľڵ㣬�������ַ��
Node* ListFind(List* L, DataType elem)
{
	assert(L);
	//��������
	Node* pcur = L->head;
	while (pcur)
	{
		if (pcur->val == elem)
		{
			return pcur;
		}
		pcur = pcur->succ;
	}
	return NULL;
}

//10.��˫��������ɾ��ָ��λ�õĽڵ㣻
void ListDelete(List* L, Node* deletenode)
{
	assert(L);
	assert(deletenode);
	deletenode->pred->succ = deletenode->succ;
	deletenode->succ->pred = deletenode->pred;
	free(deletenode);
}

//11.��ָ���Ľڵ�֮ǰ����һ��Ԫ�أ�
void ListInsertFront(Node* insert, DataType elem)
{
	assert(insert);
	Node* newnode = CreateNode(elem);
	newnode->pred = insert->pred;
	newnode->succ = insert;
	insert->pred->succ = newnode;
	insert->pred = newnode;
}

//12.��ָ���Ľڵ�֮�����һ��Ԫ�أ�
void ListInsertBack(Node* insert, DataType elem)
{
	assert(insert);
	Node* newnode = CreateNode(elem);
	newnode->pred = insert;
	newnode->succ = insert->succ;
	insert->succ->pred = newnode;
	insert->succ = newnode;
}