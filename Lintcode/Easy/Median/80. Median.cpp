#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &nums, int left, int right) {
	int temp = nums[left];
	nums[left] = nums[right];
	nums[right] = temp;
	return;
}
int getMinK(vector<int> &nums, int left, int right, int k) {
	if (left < right) {
		int i = left - 1;
		int j = left;
		for (; j < right; j++) {
			if (nums[j] < nums[right]) {
				i++;
				swap(nums, i, j);
			}
		}
		//ensure that from nums[0] to nums[i], all are smaller than/equal to nums[right]
		//but from nums[0] to nums[i], they are not sequencial.
		swap(nums, i + 1, right);
		if (k == i + 1) return nums[i + 1];
		else if (k <= i) return getMinK(nums, left, i, k);
		else return getMinK(nums, i + 2, right, k);
	}
	else {
		return nums[left];
	}
}
int median(vector<int> &nums) {
	// write your code here
	return getMinK(nums, 0, nums.size()-1, (nums.size()-1)/2);
}

void quick_sort(int* arr, int left, int right) {
	int l = left;
	int r = right;
	int temp = 0;
	if (l < r) {
		temp = arr[l];
		while (l != r) {
			while (r > l && arr[r] >= temp)
				r--;
			arr[l] = arr[r];//note here: arr[l] < temp
			while (l < r && arr[l] <= temp)
				l++;
			arr[r] = arr[l];//note here: arr[r] > temp
		}
		arr[r] = temp;
		quick_sort(arr, left, l - 1);
		quick_sort(arr, r + 1, right);
	}
	else {
		return;
	}
}
int main() {
	int test[5] = { 1,5,3,2,4 };
	quick_sort(test, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}