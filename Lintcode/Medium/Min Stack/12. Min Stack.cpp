#include<iostream>
#include<functional>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class MinStack {
private:
	stack<int> s;
	stack<int> minS;
public:
	MinStack() {
		// do intialization if necessary
	}
	void push(int number) {
		if (minS.empty() || number <= minS.top()) {
			minS.push(number);
		}
		s.push(number);
	}
	int pop() {
		int top = s.top();
		if (top == minS.top()) {
			minS.pop();
		}
		s.pop();
		return top;
	}
	int min() {
		return minS.top();
	}
};
int main() {

}