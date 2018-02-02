#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &nums, int left, int right) {
	int temp = nums[left];
	nums[left] = nums[right];
	nums[right] = temp;
	return;
}
int getMaxK(vector<int> &nums, int left, int right, int k) {
	if (left < right) {
		int i = left - 1;
		int j = left;
		for (; j < right; j++) {
			if (nums[j] > nums[right]) {
				i++;
				swap(nums, i, j);
			}
		}
		swap(nums, i + 1, right);
		if (k == i + 1) return nums[i + 1];
		else if (k <= i) return getMaxK(nums, left, i, k);
		else return getMaxK(nums, i + 2, right, k);
	}
	else {
		return nums[left];
	}
}
int kthLargestElement(int n, vector<int> &nums) {
	return getMaxK(nums, 0, nums.size() - 1, n - 1);
}
int main() {
	vector<int> arr;
	arr.push_back(9);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(8);
	cout << kthLargestElement(3, arr) << endl;
	system("pause");
	return 0;
}