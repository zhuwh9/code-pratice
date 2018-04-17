#include<iostream>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
bool isPalindrome(int x) {
	int sum = 0, num = x;
	while (num > 0) {
		sum = sum * 10 + num % 10;
		num = num / 10;
	}
	return x == sum;
}
int main() {
	int test;
	while (1) {
		cin >> test;
		if (test == 0)
			break;
		else
			cout << isPalindrome(test) << endl;
	}
	system("pause");
	return 0;
}