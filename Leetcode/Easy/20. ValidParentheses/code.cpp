#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> parentheses;
    if (s.empty()) {
        return true;
    }
    else {
		int length = s.size();
        for (int i = 0; i < length; i++) {
			char str = s[i];
            if (parentheses.empty()) {
                parentheses.push(s[i]);
            } else {
                if (parentheses.top() == '(' && str == ')') {
                    parentheses.pop();
                } else if (parentheses.top() == '[' && str == ']') {
                    parentheses.pop();
                } else if (parentheses.top() == '{' && str == '}') {
                    parentheses.pop();
                } else {
                    parentheses.push(s[i]);
                }
            }
            
        }
        if (parentheses.empty()) {
            return true;
        } else {
            return false;
        }
    }
}

int main () {
    string s1 = "()[]{}";
    cout << isValid(s1) << endl;
    return 0;
}