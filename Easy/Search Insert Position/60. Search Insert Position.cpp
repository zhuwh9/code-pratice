#include<vector>
#include<iostream>
using namespace std;
int searchInsert(vector<int> &A, int target) {
	// write your code here
	if (A.empty()) {
		return 0;
	}
	int low = 0;
	int high = A.size() - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (A[mid] == target) {
			return mid;
		}
		else if (A[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	if (target > A[low]) {
		return low + 1;
	}
	else {
		return low;
	}
}
int main() {
	vector<int> test;
	test.push_back(1);test.push_back(3);test.push_back(5);test.push_back(6);
	cout << searchInsert(test, 5) << endl;
	cout << searchInsert(test, 2) << endl;
	cout << searchInsert(test, 7) << endl;
	cout << searchInsert(test, 0) << endl;
	system("pause");
	return 0;
}