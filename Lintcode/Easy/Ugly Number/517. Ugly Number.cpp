#include<iostream>
#include<queue>
using namespace std;
bool isUgly(int n) {
	int num = 1;
	queue<int> l2, l3, l5;
	while (num < n) {
		l2.push(2 * num);
		l3.push(3 * num);
		l5.push(5 * num);
		int l2_front = l2.front();
		int l3_front = l3.front();
		int l5_front = l5.front();
		int minNum = min(l2_front, min(l3_front, l5_front));
		if (l2_front == minNum)
			l2.pop();
		if (l3_front == minNum)
			l3.pop();
		if (l5_front == minNum)
			l5.pop();
		num = minNum;
	}
	return num == n;
}
int main() {
	int num = 8;
	cout << isUgly(num) << endl;
	num = 14;
	cout << isUgly(num) << endl;
	system("pause");
	return 0;
}