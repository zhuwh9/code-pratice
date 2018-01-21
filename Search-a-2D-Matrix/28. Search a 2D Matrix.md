# 28. Search a 2D Matrix

## Description

Write an efficient algorithm that searches for a value in an *m* x *n* matrix.

This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

## Example

Consider the following matrix:

```
[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]

```

Given `target = 3`, return `true`.

## Analysis

### 二分搜索

题目提供的条件很容易联想到二分搜索（因为数组是排好序的，行向量最后一个元素小于下一个行向量的第一个元素等）

#### 两次二分搜索

先沿着每个行向量的第一个元素进行二分搜索，确定在哪一个行向量中，然后再在这个行向量中二分搜索。

#### 一次二分搜索

直接将整个矩阵视为一维行向量进行二分搜索

### 顺序搜索

当然也可以不使用，用target和每个行向量的第一个元素及最后一个元素进行比较，确定target所在的行向量后，再在这个行向量中进行顺序搜索。