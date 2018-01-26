# 138. Subarray Sum

## Description

Given an integer array, find a subarray where the sum of numbers is **zero**. Your code should return the index of the first number and the index of the last number.

## Example

Given `[-3, 1, 2, -3, 4]`, return `[0, 2]` or `[1, 3]`.

## Analysis

如果前k个数的和等于前m个数的和（k<m)，那么k+1~m这个序列的和为0.

## Code

```c++
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
```

