#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool IsOperator(char C);
bool IsNum(char C);
int PerformOpe(int op1, int op2, char operation);
int EvaluatePostfix(string expression);


int main(int argc, char **argv) {
	string exp;
	cout << "Please Enter expression:\n" << endl;
	getline(cin, exp);
	cout << "Expression:" << exp << endl;
	cout << "The Value is:" << EvaluatePostfix(exp) << endl;
	return 0;
}

bool IsOperator(char C) {
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}
bool IsNum(char C) {
	if (C >= '0' && C <= '9')
		return true;
	return false;
}

int PerformOpe(int op1, int op2, char operation) {
	if (operation == '+')
		return op1 + op2;
	else if (operation == '-')
		return op1 - op2;
	else if (operation == '*')
		return op1 * op2;
	else if (operation == '/')
		return op1 / op2;

	else
		cout << "Unexpected Error \n";
	return -1;
}

int EvaluatePostfix(string expression) {

	stack<char> S;
	int tmp = 0;
	int op1, op2, res;

	for (int i = 0; i < expression.length(); i++) {

		//If meet ' 'or ',' continue
		if (expression[i] == ' ' || expression[i] == ',')
			continue;

		//If meet operator,calculate and push
		else if (IsOperator(expression[i])) {
			op1 = S.top();
			S.pop();
			op2 = S.top();
			S.pop();
			res = PerformOpe(op1, op2, expression[i]);
			S.push(res);
		}

		//If meet num,process and push
		else if (IsNum(expression[i])) {
			int op = 0;
			while (IsNum(expression[i]) && i < expression.length()) {
				op = op * 10 + expression[i] - '0';
				i++;
			}
			S.push(op);
			i--;
		}

	}
	return S.top();

}