#include <iostream>
using namespace std;

#define MAX_SIZE 40

int A[MAX_SIZE];
int top = -1;

int IsEmpty() {
	if (top == -1) {
		return 1;
	} else {
		return 0;
	}

}

void push(int x) {
	if (top == MAX_SIZE - 1) {
		cout << "Error:stack overflow\n";
		return;
	}
	A[++top] = x;
}

void pop() {
	if (top == -1) {
		cout << "Error:No element\n";
		return;
	}
	top--;

}

int Top() {
	return A[top];
}

void Print() {
	if (IsEmpty())
		return;
	for (int i = 0; i <= top; i++) {
		cout << A[i] << ' ';
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
		push(s);
	}
	cout << "Top is:" << Top() << endl;
	cout << "Stack is:" << endl;
	Print();
	pop();
	cout << "Stack is:" << endl;
	Print();
	cout << "Top is:" << Top() << endl;
	return 0;
}