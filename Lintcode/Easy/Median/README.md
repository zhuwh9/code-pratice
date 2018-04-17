# 80. Median

## Description

Given a unsorted array with integers, find the median of it.

A median is the middle number of the array after it is sorted.

If there are even numbers in the array, return the `N/2`-th number after sorted.

## Example

Given `[4, 5, 1, 2, 3]`, return `3`.

Given `[7, 9, 4, 5]`, return `5`.

## Challenge

O(n) time.

## Analysis

排序算法的时间复杂度平均下限是O(nlog(n))，因此先对数组排序再取中间数是不可能达到O(n)的时间复杂度的。

快速排序（Quick Sort）和堆排序的平均时间复杂度是O(nlog(n))。

由于快速排序的思想是针对某一个基准值进行双向排序，如果抛弃排序，只是将比某一个基准值小的所有数放在该基准值的左边，其余数放在该基准值右边，则时间复杂度可以达到O(n)。

## Code

```c++
void swap(vector<int> &nums, int left, int right) {
	int temp = nums[left];
	nums[left] = nums[right];
	nums[right] = temp;
	return;
}
int getMinK(vector<int> &nums, int left, int right, int k) {
	if (left < right) {
		int i = left - 1;
		int j = left;
		// ensure that from nums[0] to nums[i]
		// all elements are smaller than or equal to nums[right]
		// but from nums[0] to nums[i], they are not necessarily sequencial.
		for (; j < right; j++) {
			if (nums[j] < nums[right]) {
				i++;
				swap(nums, i, j);
			}
		}
	    // the rest are are bigger than or equal to nums[i+1]
      	swap(nums, i + 1, right);
      	// use recursion to shrink the array
      	// until the first (k-1)-th elements
      	// are smaller than or equal to k-th elements
		if (k == i + 1) return nums[i + 1];
		else if (k <= i) return getMinK(nums, left, i, k);
		else return getMinK(nums, i + 2, right, k);
	}
	else {
		return nums[left];
	}
}
int median(vector<int> &nums) {
	// write your code here
	return getMinK(nums, 0, nums.size()-1, (nums.size()-1)/2);
}
```



