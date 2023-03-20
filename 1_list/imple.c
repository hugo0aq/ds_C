#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *link;

} Node;
Node *Node_Init(int elem);

void main() {
	Node *A;
	A = NULL;
	A = Node_Init(2);
	printf("A address:%p,data:%d\n", A, (*A).data);


}

Node *Node_Init(int elem) {
	Node *tmp = (Node *)malloc(sizeof(Node));
	(*tmp).data = elem;
	(*tmp).link = NULL;
	return tmp;
}