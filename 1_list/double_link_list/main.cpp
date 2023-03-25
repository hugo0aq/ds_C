#include <iostream>
#include "dllist.h"
using namespace std;

int main(int argc, char **argv) {
	Node *head = NULL;
	int n = 0, data;
	cout << "Enter the number of data:\n";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter the data:\n";
		cin >> data;
		head = InsertAtTail(head, data);
	}
	cout << "The list is:\n";
	Print(head);
	ReversePrint(head);
	return 0;
}