#include <stdio.h>


typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;



void Enqueue(int x) {
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = x;
	tmp->next = NULL;
	if (front == NULL && rear == NULL) {
		front = tmp;
		rear = tmp;
		return;
	}
	rear->next = tmp;
	rear = tmp;

}

void Dequeue() {
	Node *tmp = front;
	if (front == NULL)
		return;
	if (front == rear) {
		front = NULL;
		rear = NULL;
	} else
		front = front->next;
	free(tmp);
}

int Front() {
	if (front == NULL) {
		printf("Queue is empty\n");
		return 1;
	}
	return front->data;
}

void Print() {
	Node *temp = front;
	temp = front;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	free(temp);
	temp = NULL;
}

int main() {
	Enqueue(2);
	Print();
	Enqueue(4);
	Print();
	Enqueue(6);
	Print();
	Dequeue();
	Print();
	Enqueue(8);
	Print();
	return 0;

}