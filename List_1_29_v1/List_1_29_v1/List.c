#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//1.初始化双向链表；
void ListInit(List* L)
{
	//为哨兵节点申请空间；
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
	//初始化哨兵节点；
	L->head = head;
	L->head->succ = tail;
	L->head->pred = NULL;

	L->tail = tail;
	L->tail->succ = NULL;
	L->tail->pred = head;
}

//2.销毁双向链表；
void ListDestroy(List* L)
{
	assert(L);//确保链表的指针有效；
	Node* pcur = L->head;//从头结点开始；
	while (pcur)
	{
		Node* next = pcur->succ;//记录下一个节点；
		free(pcur);//删除当下节点；
		pcur = next;//更新节点；
	}

	// 将链表的头指针和尾指针置为空，避免悬挂指针;
	L->head = NULL;
	L->tail = NULL;
}

//3.双向链表申请新的节点；
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

//4.双向链表的头插；
void ListPushFront(List* L, DataType elem)
{
	assert(L);
	//申请新的节点；
	Node* newnode = CreateNode(elem);
	//修改指针的指向；
	newnode->succ = L->head->succ;
	newnode->pred = L->head;
	newnode->succ->pred = newnode;
	L->head->succ = newnode;
}

//5.双向链表的尾插；
void ListPushBack(List* L, DataType elem)
{
	assert(L);
	//申请新的节点；
	Node* newnode = CreateNode(elem);
	//修改指针的指向；
	newnode->pred = L->tail->pred;
	newnode->succ = L->tail;
	newnode->pred->succ = newnode;
	L->tail->pred = newnode;

}

//6.双向链表的打印函数；
void ListPrint(List* L)
{
	assert(L);
	//用指针遍历；
	Node* pcur = L->head->succ;
	while (pcur != L->tail)
	{
		printf("%d - ", pcur->val);
		pcur = pcur->succ;
	}
	printf("\n");
}

//7.双向链表的头删函数；
void ListPopFront(List* L)
{
	assert(L);
	//记录头哨兵节点的下一个节点；
	Node* deletenode = L->head->succ;
	deletenode->succ->pred = L->head;
	L->head->succ = deletenode->succ;
	free(deletenode);
}

//8.双向链表的尾删函数；
void ListPopBack(List* L)
{
	assert(L);
	//记录尾哨兵节点的前一个节点；
	Node* deletenode = L->tail->pred;
	deletenode->pred->succ = L->tail;
	L->tail->pred = deletenode->pred;
	free(deletenode);
}

//9.在链表中寻找值为elem的节点，返回其地址；
Node* ListFind(List* L, DataType elem)
{
	assert(L);
	//遍历链表；
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

//10.在双向链表中删除指定位置的节点；
void ListDelete(List* L, Node* deletenode)
{
	assert(L);
	assert(deletenode);
	deletenode->pred->succ = deletenode->succ;
	deletenode->succ->pred = deletenode->pred;
	free(deletenode);
}

//11.在指定的节点之前插入一个元素；
void ListInsertFront(Node* insert, DataType elem)
{
	assert(insert);
	Node* newnode = CreateNode(elem);
	newnode->pred = insert->pred;
	newnode->succ = insert;
	insert->pred->succ = newnode;
	insert->pred = newnode;
}

//12.在指定的节点之后插入一个元素；
void ListInsertBack(Node* insert, DataType elem)
{
	assert(insert);
	Node* newnode = CreateNode(elem);
	newnode->pred = insert;
	newnode->succ = insert->succ;
	insert->succ->pred = newnode;
	insert->succ = newnode;
}