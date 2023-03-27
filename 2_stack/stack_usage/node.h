#ifndef __NODE_H__
#define __NODE_H__

struct Node {
	int data;
	struct Node *next;
} ;

Node *Insert(Node *head, int data, int n);
Node *Delete(Node *head, int n);    //delete function
void Print(Node *head);
void ReversePrint(Node *p);
Node *Reverse(Node *p);
Node *ReverseList(Node *top);
#endif