# 14. First Position Of Target

## Description

For a given sorted array (ascending order) and a `target` number, find the first index of this number in `O(log n)` time complexity.

If the target number does not exist in the array, return `-1`.

## Example

If the array is `[1, 2, 3, 3, 4, 5, 10]`, for given target `3`, return `2`.

## Analysis

时间复杂度O(log n) => 二分查找

不同之处在于：二分查找是找到这个数就会返回，但是现在是必须找到第一个target数的下标。

以array = [1, 2, 3, 3, 3, 3, 4, 4, 5, 6, 7]，target = 3为例：

### 第一次迭代：

​	low = 0, high = 10, mid = (0+10)/2 + low = 5，此时array[mid]已经是target数了，但是还不能返回下标，因为不是第一个出现的target数。此时high = mid而不是high = mid - 1或low = mid + 1。

​	搜索范围缩小到[1, 2, 3, 3, 3, 3]

### 第二次迭代：

​	low = 0, high = 5, mid = (0 + 5) / 2 + low = 2，此时array[mid]也是target数，但是仍不能返回下标，同理，high = mid。

​	搜索范围缩小到[1, 2, 3]

### 第三次迭代~最后一次迭代：

​	迭代过程不断缩小范围，最后缩小到[3]。如果此时array[mid]就是target数，那么就返回这个下标，否则返回-1.