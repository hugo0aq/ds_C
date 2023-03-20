#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *link;
} Node;

int  isEmpty(Node *L);
Node *Insert(Node *head, int num);
void Print(Node *head);

int main() {
	Node *head;
	head = NULL;
	int n, i, x;
	printf("Enter the number of data:\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter the data:\n");
		scanf("%d", &x);
		head = Insert(head, x);
		Print(head);
	}
	printf("\n");
	if (!isEmpty(head))
		printf("List Not empty!\n");
	else
		printf("List Empty!\n");
	return 0;
}

Node *Insert(Node *head, int num) {
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));
	(*tmp).data = num;
	(*tmp).link = NULL;
	if (head != NULL)
		tmp->link = head;
	head = tmp;
	return head;

}

void Print(Node *head) {
	printf("The list is:\n");
	while (head != NULL) {

		printf("% d", head->data);
		head = head->link;
	}
	printf("\n");
}

int  isEmpty(Node *L) {
	return L == NULL;
}