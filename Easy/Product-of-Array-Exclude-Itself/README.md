# 50. Product of Array Exclude Itself

## Description

Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B **WITHOUT** divide operation.

## Example

For A = `[1, 2, 3]`, return `[6, 3, 2]`.

## Analysis

第一反应是两层for循环，除了下标相同的不乘，其余下标累乘。然而这种方法时间复杂度O(n)，太蠢了。

其实可以利用好已有的数组，先把每个下标的左、右的累乘结果通过遍历保存，然后再根据具体的下标返回结果。

## Code

``` c++
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
```