#include<iostream>

using namespace std;

typedef struct Node{
	int data;
	Node* next;
}Node;
//ÈëÕ»£» 
void Push(Node*& top, int val)
{
	Node* newnode = new Node;
	newnode -> next = NULL;
	newnode -> data = val;
	if(top == NULL)
	{
		top = newnode;
		cout << "Node with value " << top -> data << " " << "is pushed in stack." << endl;
	}
	else
	{
		newnode -> next = top;
		top = newnode;
		cout << "Node with value " << top -> data << " " << "is pushed in stack." << endl;
	}
}
//³öÕ»£» 
void Pop(Node*& top)
{
	if(top == NULL) cout << "Stack is null." << endl;
	else
	{
		Node* dnode = top;
		top = top -> next;
		cout << "Node with value " << dnode -> data << " " << "is poped out." << endl;
		delete dnode;
		dnode = NULL;
		
	}
}
void DestroyStack(Node*& top)
{
	while(top)
	{
		delete top;
		top = top -> next;
	}
	top = NULL;
}
int main()
{
	Node* top = NULL;
	Push(top, 10); 
	Push(top, 12);
	Push(top, 14); 
	cout << "---------------------------------" << endl;
	Pop(top);
	Pop(top);
	Pop(top);
	DestroyStack(top);
	return 0;
} 
