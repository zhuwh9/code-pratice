#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &nums, int left, int right) {
	int temp = nums[left];
	nums[left] = nums[right];
	nums[right] = temp;
}
int partitionArray(vector<int> &nums, int k) {
	if (nums.size() == 0) {
		return 0;
	}
	int back = nums.size() - 1;
	int front = 0;
	// put numbers larger than k right
	while (1) {
		while (nums[front] < k) {
			front++;
		}
		while (nums[back] >= k) {
			back--;
		}
		if (front >= back) {
			break;
		}
		swap(nums, front, back);
		front++;
		back--;
	}
	// put k at the middle
	back = nums.size();
	int index = front;
	for (int i = front; i < back; i++) {
		if (nums[i] == k) {
			swap(nums, i, index);
			index++;
		}
	}
	return front;
}
int main() {
	vector<int> nums;
	nums.push_back(9);
	nums.push_back(9);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(6);
	nums.push_back(9);
	nums.push_back(10);
	int k = 9;
	cout << partitionArray(nums, k) << endl;
	system("pause");
	return 0;
}