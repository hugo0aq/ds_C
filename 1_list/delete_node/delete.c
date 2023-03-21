#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
} Node;


Node *head;   //global node head ptr

void Insert(int data, int n);
void Delete(int n);     //delete function
void Print();

void main() {
	int i, x, n, m;
	head = NULL;
	printf("Enter the number of data:\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter the data:\n");
		scanf("%d", &x);
		Insert(x, i + 1);
	}
	Print();
	printf("Delete number:\n");
	scanf("%d", &m);
	Delete(m);
	Print();
}

void Print() {
	Node *tmpptr = head;
	printf("The list is:\n");
	while (tmpptr != NULL) {
		printf("%d", tmpptr->data);
		tmpptr = tmpptr->next;
	}
	printf("\n");
}


void Insert(int data, int n) {
	int i;
	Node *tmp1 = (Node *)malloc(sizeof(Node));
	tmp1->data = data;
	tmp1->next = NULL;
	if (n == 1) {
		tmp1->next = head;
		head = tmp1;
		return;
	}
	Node *tmp2 = head;
	for (i = 0; i < n - 2; i++) {
		tmp2 = tmp2->next;
	}
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
}


void Delete(int n) {              //delete function
	int i;
	Node *tmp1 = head;
	if (n == 1) {                 //n=1 special situation
		head = tmp1->next;        //head the next node
		free(tmp1);               //free the memory of deleted node(malloc in Insert())
		return;
	}
	for (i = 0; i < n - 2; i++) {
		tmp1 = tmp1->next;
	}
	Node *tmp2 = tmp1->next;
	tmp1->next = tmp2->next;      //fix the link
	free(tmp2);                   //free the memory of deleted node

}