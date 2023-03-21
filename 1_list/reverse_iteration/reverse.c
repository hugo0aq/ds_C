#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
} Node;




Node *Insert(Node *head, int data, int n);
void Delete(int n);     //delete function
void Print(Node *head);
Node *Reverse(Node *head);

void main() {
	int i, x, n, m;
	Node *head;    //local node head ptr
	head = NULL;
	printf("Enter the number of data:\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter the data:\n");
		scanf("%d", &x);
		head = Insert(head, x, i + 1);
	}
	Print(head);
	head = Reverse(head);
	printf("Reversed node is:\n");
	Print(head);
}

void Print(Node *head) {
	printf("The list is:\n");
	while (head != NULL) {
		printf("%d", head->data);
		head = head->next;
	}
	printf("\n");
}


Node *Insert(Node *head, int data, int n) {
	int i;
	Node *tmp1 = (Node *)malloc(sizeof(Node));
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

Node *Reverse(Node *head) {
	Node *now = head;
	Node *prev = NULL;
	Node *next;    //three ptr restore three nodes address
	while (now != NULL) {
		next = now->next;
		now->next = prev;
		prev = now;
		now = next;
	}
	head = prev;
	return head;
}
