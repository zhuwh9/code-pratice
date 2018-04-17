#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//naive solution
bool isUgly(int num) {
	while (1) {
		if (num % 2 == 0) {
			num /= 2;
		}
		else if (num % 3 == 0) {
			num /= 3;
		}
		else if (num % 5 == 0) {
			num /= 5;
		}
		else {
			break;
		}
	}
	if (num == 1) {
		return true;
	}
	else {
		return false;
	}
}
int nthUglyNumber(int n) {
	int count = 0;
	int num = 0;
	while (count < n) {
		num++;
		if (isUgly(num)) {
			count++;
		}
	}
	return num;
}
// O(n) way
int nthUglyNumber(int n) {
	int count = 1;
	int num = 1;
	queue<int> l2, l3, l5;
	while (count != n) {
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
		count++;
	}
	return num;
}
int main() {
	int n = 1665;
	cout << nthUglyNumber(n) << endl;
	system("pause");
	return 0;
}