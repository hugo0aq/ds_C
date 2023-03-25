#include <iostream>
#include "node.h"
using namespace std;




Node *Insert(Node *head, int data, int n) {
	int i;
	Node *tmp1 = new Node();
	tmp1->data = data;
	tmp1->next = NULL;
	if (n == 1) {
		tmp1->next = head;
		head = tmp1;
		return head;
	}
	Node *tmp2 = head;
	for (i = 0; i < n - 2; i++) {
		tmp2 = tmp2->next;
	}
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;

	return head;
}

//void Print(Node *head) {
//	printf("The list is:\n");
//	while (head != NULL) {
//		printf("%d", head->data);
//		head = head->next;
//	}
//	printf("\n");
//}

void Print(Node *p) {         //recursion
	if (p == NULL) {
		printf("\n");
		return;
	}

	printf("%d ", p->data);
	Print(p->next);
}

void ReversePrint(Node *p) {
	if (p == NULL) {
		return;
	}
	ReversePrint(p->next);
	printf("%d ", p->data);
    
}

Node *Delete(Node *head, int n) {             //delete function
	int i;
	Node *tmp1 = head;
	if (n == 1) {                 //n=1 special situation
		head = tmp1->next;        //head the next node
		delete tmp1;
		return head;               //free the memory of deleted node(malloc in Insert())
	} else {
		for (i = 0; i < n - 2; i++) {
			tmp1 = tmp1->next;
		}
		Node *tmp2 = tmp1->next;
		tmp1->next = tmp2->next;      //fix the link
		delete tmp2;                   //free the memory of deleted node
		return head;
	}

}

//Node *Reverse(Node *head) {
//	Node *now = head;
//	Node *prev = NULL;
//	Node *next;    //three ptr restore three nodes address
//	while (now != NULL) {
//		next = now->next;
//		now->next = prev;
//		prev = now;
//		now = next;
//	}
//	head = prev;
//	return head;
//}

Node * Reverse(Node *p){     //recursion reverse
	if(p==NULL|p->next==NULL){
		return p;
	}
	Node *new_head=Reverse(p->next);
	Node *q=p->next;
	q->next=p;
	p->next=NULL;
    return new_head;
}