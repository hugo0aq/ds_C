#include <stdio.h>
#include <stdlib.h>

typedef struct Node {    //typedef struct 定义链表节点并赋名便于定义
	int data;
	struct Node *link;
} Node;

int  isEmpty(Node *L);  //判断空链表函数声明，空链表返回1
Node *Insert(Node *head, int num); //head节点插入函数声明
void Print(Node *head); //head节点起遍历链表函数声明

int main() {
	Node *head;    //定义head指针，指向链表第一个节点
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
