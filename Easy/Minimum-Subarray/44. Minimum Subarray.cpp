#include<iostream>
#include<vector>
using namespace std;
int minSubArray(vector<int> &nums) {
	// write your code here
	int result = 9999;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		sum = sum > nums[i] ? nums[i] : sum;
		result = result > sum ? sum : result;
	}
	return result;
}
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(-1);
	nums.push_back(-2);
	nums.push_back(1);
	cout << minSubArray(nums) << endl;
	system("pause");
	return 0;
}