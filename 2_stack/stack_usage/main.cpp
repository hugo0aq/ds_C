#include <iostream>
#include <stack>
#include <cstring>
#include "node.h"
#include "CheckBalance.h"
using namespace std;


void ReverseString(char *A, int n) {
	stack<char>S;
	for (int i = 0; i < n; i++) {
		S.push(A[i]);
	}
	for (int i = 0; i < n; i++) {
		A[i] = S.top();
		S.pop();
	}
}



int main(int argc, char **argv) {
	Node *top = NULL;
	int n, s;
	char A[40] = "{([])";
	cout << A << endl;
//  @Reverse String Test
//	ReverseString(A, strlen(A));
//	cout << A << endl;



//  @ Reverse List Test
//	cout<<"Enter the number of list:\n";
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cout << "Enter the data:\n";
//		cin >> s;
//		top=Insert(top,s,i+1);
//	}
//	Print(top);
//	top=ReverseList(top);
//	Print(top);

	cout << CheckBalance(A, strlen(A)) << endl;

	return 0;
}