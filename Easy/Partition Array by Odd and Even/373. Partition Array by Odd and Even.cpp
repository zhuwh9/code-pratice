#include<iostream>
#include<vector>
using namespace std;
void swapOddAndEven(vector<int> &nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
void partitionArray(vector<int> &nums) {
	int odd_index = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] % 2 == 1) {
			swapOddAndEven(nums, i, odd_index);
			odd_index++;
		}
	}
}
int main() {
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	partitionArray(arr);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}