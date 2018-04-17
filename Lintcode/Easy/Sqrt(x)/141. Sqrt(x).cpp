#include<iostream>
using namespace std;
int sqrt(int x) {
	int low = 0;
	int high = 46341;//avoid overflow
	int mid = 0;
	while (low <= high) {
		if (mid == low + (high - low) / 2) {
			break;
		}
		mid = low + (high - low) / 2;
		int square = mid * mid;
		if (square == x) {
			return mid;
		}
		else if (x > square) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	return mid;
}