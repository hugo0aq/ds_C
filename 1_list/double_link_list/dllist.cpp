#include <iostream>
#include "dllist.h"
using namespace std;

Node *GetNewNode(int x) {
	Node *tmp = new Node();
	tmp->data = x;
	tmp->prev = NULL;
	tmp->next = NULL;
	return tmp;
}

Node *InsertAtHead(Node *p, int x) { //insert at head node
	Node *newnode = GetNewNode(x);
	if (p == NULL) {
		p = newnode;
		return p;
	}
	p->prev = newnode;
	newnode->next = p;
	return newnode;
}

Node *InsertAtTail(Node *p, int x) { //insert at tail node
	Node *newnode = GetNewNode(x);
	if (p == NULL) {
		p = newnode;
		return p;
	}
	while (p->next != NULL) {
		p = p->next;
	}
	newnode->prev = p;
	p->next = newnode;
	while (p->prev != NULL)
		p = p->prev;
	return p;
}

void Print(Node *p) { //print the list

	if (p == NULL) {
		cout << "\n";
		return;
	}
	cout << p->data;
	Print(p->next);

}

void ReversePrint(Node *p) { //reverse print the list
	if (p == NULL)
		return;
	while (p->next != NULL)
		p = p->next;
	cout << "The Reverse list is:\n";
	while (p != NULL) {
		cout << p->data;
		p = p->prev;
	}
	cout << "\n";
}