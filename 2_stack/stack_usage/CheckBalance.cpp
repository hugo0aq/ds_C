#include <iostream>
#include <stack>
#include "CheckBalance.h"
using namespace std;

bool CheckBalance(char *c, int n) {
	stack<char>S;
	for (int i = 0; i < n; i++) {
		if (c[i] == '{' || c[i] == '[' || c[i] == '(') {
			S.push(c[i]);
		} else if (c[i] == '}' || c[i] == ']' || c[i] == ')') {
			if (S.empty() || !((S.top() == '{' && c[i] == '}')|| (S.top() == '[' && c[i] == ']') || (S.top() == '(' && c[i] == ')'))) {
				return false;
			} else {
				S.pop();
			}

		}
	}
	return S.empty() ? true : false;
}
