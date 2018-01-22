#include<iostream>
#include<math.h>
#include<cmath>
#include<vector>
using namespace std;
// one pass algorithm, 100% accepted
int maxSubArray(vector<int> &nums) {
	// write your code here
	int result = -9999;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		sum = sum > nums[i] ? sum : nums[i];
		result = result > sum ? result : sum;
	}
	return result;
}

// a naive way, time costly, 85% passed
//int maxSubArray(vector<int> &nums) {
//	int len = nums.size();
//	int result = -9999;
//	for (int i = 1; i <= len; i++) {
//		for (int j = 0; j <= len - i; j++) {
//			int sum = 0;
//			for (int m = j; m < j + i; m++) {
//				sum += nums[m];
//			}
//			if (sum > result) {
//				result = sum;
//			}
//		}
//	}
//	return result;
//}
int main() {
	vector<int> nums;
	nums.push_back(-2);nums.push_back(2);nums.push_back(-3);
	nums.push_back(4);nums.push_back(-1);nums.push_back(2);
	nums.push_back(1);nums.push_back(-5);nums.push_back(3);
	cout << maxSubArray(nums) << endl;
	system("pause");
	return 0;
}