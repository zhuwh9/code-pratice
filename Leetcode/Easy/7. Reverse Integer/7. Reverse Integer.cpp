#include<iostream>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
int reverse(int x) {
	if (x == 0) return x;
	int count = 0;
	bool isNegative = false;
	int remainder, result = 0;
	if (x < 0) {
		isNegative = true;
		x = -x;
	}
	int num = x;
	while (1) {
		remainder = num % 10;
		if (remainder == 0) {
			num /= 10;
			x /= 10;
		}
		else {
			break;
		}
	}
	while (num > 0) {
		count++;
		num /= 10;
	}
	num = 0;
	for (int i = 0; i < count; i++) {
		remainder = x % 10;
		result += remainder * pow(10, count - i - 1);
		x /= 10;
	}
	if (result < 0) {
		return 0;
	}
	if (isNegative) {
		result = -1 * result;
	}
	return result;
}
int main() {
	while (1) {
		int test;
		cin >> test;
		if (test == 0) {
			break;
		}
		else {
			cout << reverse(test) << endl;
		}
	}
	system("pause");
	return 0;
}