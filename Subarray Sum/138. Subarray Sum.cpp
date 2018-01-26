#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> subarraySum(vector<int> &nums) {
	unordered_map<int, int> k_sum;
	vector<int> result;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum == 0) {
			result.push_back(0);
			result.push_back(i);
			return result;
		}
		if (k_sum.count(sum) == 0) {
			k_sum[sum] = i;
		}
		else {
			result.push_back(k_sum[sum] + 1);
			result.push_back(i);
			return result;
		}
	}
}