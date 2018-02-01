#include<iostream>
#include<vector>
using namespace std;
// recursive
//int climbStairs(int n) {
//	if (n < 1) {
//		return 0;
//	}
//	else if (n == 1) {
//		return 1;
//	}
//	else if (n == 2) {
//		return 2;
//	}
//	else {
//		return climbStairs(n - 1) + climbStairs(n - 2);
//	}
//}
// iteration way
int climbStairs(int n) {
	if (n < 1) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else {
		int first = 1;
		int second = 2;
		int t = 0;
		for (int i = 3; i <= n; i++) {
			t = first + second;
			first = second;
			second = t;
		}
		return t;
	}
}