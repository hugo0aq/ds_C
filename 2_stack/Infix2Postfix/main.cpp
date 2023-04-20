#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool HigherPrec(char ope1, char ope2);

bool IsOperator(char C);

bool IsNum(char C);


string Infix2Postfix(string expression);


int main(int argc, char **argv) {
	string expression;

	cout << "Enter the expression:" << endl;
	cin >> expression;
	string postfix = Infix2Postfix(expression);

	cout << "Output:" << postfix << endl;


	return 0;
}

string Infix2Postfix(string expression) {
	stack<char>S;
	string res = "";

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == ' ' || expression[i] == ',')
			continue;

		else if (IsOperator(expression[i])) {
			while (!S.empty() && S.top() != '(' && HigherPrec(S.top(), expression[i])) {
				res += S.top();
				S.pop();
			}
			S.push(expression[i]);
		} else if (IsNum(expression[i])) {
			res += expression[i];
		} else if (expression[i] == '(') {
			S.push(expression[i]);
		}

		else if (expression[i] == ')') {
			while (!S.empty() && S.top() !=  '(') {
				res += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.empty()) {
		res += S.top();
		S.pop();
	}

	return res;

}


bool IsOperator(char C) {
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;
	return false;
}

int GetOperatorWeight(char op) {
	int weight = -1;

	if (op == '+' || op == '-') {
		weight = 1;

	} else if (op == '*' || op == '/') {
		weight = 2;
	}
	return weight;
}

bool IsNum(char C) {
	if (C >= '0' && C <= '9')
		return true;
	if (C >= 'a' && C <= 'z')
		return true;
	if (C >= 'A' && C <= 'Z')
		return true;
	return false;
}






bool HigherPrec(char ope1, char ope2) {
	int opweight1 = GetOperatorWeight(ope1);
	int opweight2 = GetOperatorWeight(ope2);

	if (opweight1 == opweight2) {
		return true;
	}
	return opweight1 > opweight2 ?  true : false;
}