#include <iostream>
#include "node.h"
using namespace std;

int main(int argc, char **argv) {
	int i, x, n, m, s;
	Node *head;    //local node head ptr
	head = NULL;
	printf("Enter the number of data:\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter the data:\n");
		scanf("%d", &x);
		head = Insert(head, x, i + 1);
	}
	printf("The list is:\n");
	Print(head);
	head = Reverse(head);
	printf("Reversed node is:\n");
	Print(head);
	cout << "delete the node:\n";
	cin >> s;
	head = Delete(head, s);
	Print(head);
	return 0;
}