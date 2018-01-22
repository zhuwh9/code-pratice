# 41. Maximum Subarray

## Description

Given an array of integers, find a contiguous subarray which has the largest sum.

## Example

Given the array `[−2,2,−3,4,−1,2,1,−5,3]`, the contiguous subarray `[4,−1,2,1]` has the largest sum = `6`.

## Analysis

贪心算法的典型例子，先贴代码，然后解释：

```c++
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
```

最初将result设为一个理论最小值（不需要是整形数的最小值，当然这样会有极端例子导致出错）

然后用一个sum变量记录从某个数开始，连续若干个数的和为当前最大值，如果sum += nums[i]后的结果小于nums[i]，说明得到这个sum的子序列还不如单独一个nums[i]大，因此将sum更新为nums[i]，否则继续延长这个子序列。

result变量是用于保存子序列的最大值的，因为子序列得到最大值未必是全局最大值，所以result不断取这些连续子序列的最大值保留。

