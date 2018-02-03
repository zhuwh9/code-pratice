#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int reverseInteger(int n) {
	if (n == 0) {
		return 0;
	}
	queue<int> num;
	int isNagative = 1;
	if (n < 0) {
		isNagative = -1;
		n = -1 * n;
	}
	queue<int> n_queue;
	while (n != 0) {
		n_queue.push(n % 10);
		n /= 10;
	}
	int len = n_queue.size();
	if (len >= 10) {
		return 0;//here should consider more
	}
	int result = 0;
	for (int i = 0; i < len; i++) {
		result += n_queue.front() * (int)pow(10, len - 1 - i);
		n_queue.pop();
	}
	return result * isNagative;
}
int main() {
	int x = 123;
	cout << reverseInteger(x) << endl;
	int y = -123;
	cout << reverseInteger(y) << endl;
	system("pause");
	return 0;
}