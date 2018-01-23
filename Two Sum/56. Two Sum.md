# 56. Two Sum

## Description

Given an array of integers, find two numbers such that they add up to a specific target number.

The function `twoSum` should return *indices* of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.

## Example

numbers=`[2, 7, 11, 15]`, target=`9`

return `[0, 1]`

## Challenge

Either of the following solutions are acceptable:

- O(n) Space, O(nlogn) Time
- O(n) Space, O(n) Time

## Analysis

第一个想法是用暴力搜索，两层for循环导致时间复杂度为O(n²)，显然当数组非常大的时候会超时。

第二个想法是根据映射关系value->index保存值和下标，用target去减当前数得到diff，然后查看映射表里有没有diff，如果有，把映射得到的index及当前下标返回。

## Code

``` c++
vector<int> twoSum(vector<int> &numbers, int target) {
	// write your code here
	unordered_map<int, int> num_map;
	for (int i = 0; i < numbers.size(); i++) {
		num_map[numbers[i]] = i;
	}
	for (int i = 0; i < numbers.size(); i++) {
		int diff = target - numbers[i];
		if (num_map.count(diff) && num_map.at(diff) != i) {
			int index = num_map.at(diff);
			vector<int> result;
			if (i > index) {
				result.push_back(index);
				result.push_back(i);
			}
			else {
				result.push_back(i);
				result.push_back(index);
			}
			return result;
		}
	}
}
```

