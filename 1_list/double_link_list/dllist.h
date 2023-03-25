#ifndef _DLLIST_H_
#define _DLLIST_H_

struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};

Node *GetNewNode(int x);

Node *InsertAtHead(Node *p, int x); //insert at head node

Node *InsertAtTail(Node *p, int x); //insert at tail node

void Print(Node *head);     //print the list

void ReversePrint(Node *p); //reverse print the list
#endif