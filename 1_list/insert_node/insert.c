#include <stdio.h>
#include <stdlib.h>

typedef struct Node {               //typedef redefine Node name
	int data;
	struct Node *next;
} Node;


Node *head;                          //head node
void Insert(int data, int n);
void Print();

void main() {
	int i, n, x;
	head = NULL;  //empty list
	printf("Enter the number of datas:\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter the data:\n");
		scanf("%d", &x);
		Insert(x, i + 1);
	}
	Print();

}

void Insert(int data, int n) {    //Insert function
	int i;
	Node *tmp1 = (Node *)malloc(sizeof(Node));
	tmp1->data = data;
	tmp1->next = NULL;
	if (n == 1) {                 //head node
		tmp1->next = head;
		head = tmp1;
		return;
	}
	Node *tmp2 = head;            //tmp2 to find target node
	for (i = 0; i < n - 2; i++) {
		tmp2 = tmp2->next;
	}
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
}

void Print() {                    //print function
	Node *tmp = head;
	printf("The list is:");
	while (tmp != NULL) {
		printf(" %d", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
