#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValidParentheses(string &s) {
	stack<char> t;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			t.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			char top = t.top();
			if (top == '(' && s[i] == ')') {
				t.pop();
			}
			else if (top == '[' && s[i] == ']') {
				t.pop();
			}
			else if (top == '{' && s[i] == '}') {
				t.pop();
			}
			else {
				return false;
			}
		}
	}
	if (t.empty()) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	string false_one = "([)]";
	string false_two = "(]";
	string true_one = "()[]{}";
	cout << isValidParentheses(false_one) << endl;
	cout << isValidParentheses(false_two) << endl;
	cout << isValidParentheses(true_one) << endl;
	system("pause");
	return 0;
}