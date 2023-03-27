#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *top = NULL;

int IsEmpty() {
	if (top == NULL) {
		return 1;
	} else {
		return 0;
	}

}

void Push(int x) {
	Node *tmp = new Node();
	tmp->data = x;
	tmp->next = top;
	top = tmp;
}

void Pop() {
	Node *tmp ;
	if (top == NULL)
		return;
	tmp = top;
	top = top->next;
	delete tmp;

}

int Top() {
	return top->data;
}

void Print() {
	Node *tmp = top;
	while(tmp != NULL) {
		cout << tmp->data<<' ';
		tmp = tmp->next;
	}
	cout << endl;
}
int main(int argc, char **argv) {
	int n, s;
	cout << "Enter the number:\n";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter the data:\n";
		cin >> s;
		Push(s);
	}
	cout << "Top is:" << Top() << endl;
	cout << "Stack is:" << endl;
	Print();
	Pop();
	cout << "Stack is:" << endl;
	Print();
	cout << "Top is:" << Top() << endl;

	return 0;
}