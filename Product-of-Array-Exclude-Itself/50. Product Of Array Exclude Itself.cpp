#include<iostream>
#include<vector>
using namespace std;
vector<long long> productExcludeItself(vector<int> &nums) {
	// write your code here
	const int n = nums.size();
	long long* left = new long long[n];
	long long* right = new long long[n];
	left[0] = 1;
	for (int i = 1; i < n; i++) {
		left[i] = left[i - 1] * nums[i-1];
	}
	right[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		right[i] = right[i + 1] * nums[i + 1];
	}
	vector<long long> result;
	for (int i = 0; i < n; i++) {
		result.push_back(left[i] * right[i]);
	}
	return result;
}
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<long long> result = productExcludeItself(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}