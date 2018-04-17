#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> &array, int target) {
	// write your code here
	if (array.size() == 0) {
		return -1;
	}
	int low = 0;
	int high = array.size()-1;

	while (low < high) {
		int mid = low + (high - low) / 2;
		if (array[mid] > target) {
			high = mid - 1;
		}
		else if (array[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	
	if (array[low] == target) {
		return low;
	}
	else {
		return -1;
	}
}
int main() {
	int temp = 5 / 2;
	cout << temp << endl;
	system("pause");
	return 0;
}