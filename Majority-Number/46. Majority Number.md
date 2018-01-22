# 46. Majority Number

## Description

Given an array of integers, the majority number is the number that occurs `more than half` of the size of the array. Find it.

## Example

Given `[1, 1, 1, 1, 2, 2, 2]`, return `1`

## Challenge

O(*n*) time and O(*1*) extra space

## Analysis

challenge的条件非常严格：

O(1)空间复杂度：意味着只能借助固定数量的临时变量

O(n)时间复杂度：意味着只能遍历固定次数次数组

## Algorithm

<http://www.geeksforgeeks.org/majority-element/>

这里是一篇论文： <http://www.cs.utexas.edu/~moore/best-ideas/mjrty/>

这里用的算法是：[MJRTY - A Fast Majority Vote Algorithm](http://www.cs.utexas.edu/users/boyer/mjrty.ps.Z)

- 简单来讲，就是不断对某个议案投票，如果有人有别的议案，则将前面认为的议案的cnt减1，减到0换一个议案。如果存在majority number，那么这个议案一定不会被减到0，最后会胜出。


- 投票完成后，要对majority number进行检查，以排除不存在majority number的情况。如 1，2，3，4这样的数列，是没有majority number的。很简单，统计一下结果议案的票数，没有过半就是没有majority number.

## Pseudo code

```
1.  Initialize index and count of majority element
     maj_index = 0, count = 1
2.  Loop for i = 1 to size – 1
    (a)If a[maj_index] == a[i]
        count++
    (b)Else
        count--;
    (c)If count == 0
        maj_index = i;
        count = 1
3.  Return a[maj_index]
```

