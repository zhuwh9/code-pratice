# 60. Search Insert Position

## Description

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume **NO** duplicates in the array.

## Example

`[1,3,5,6]`, 5 → 2

`[1,3,5,6]`, 2 → 1

`[1,3,5,6]`, 7 → 4

`[1,3,5,6]`, 0 → 0

## Challenge

O(log(n)) time

## Analysis

题目条件（sorted array, O(log(n)) time)说明要用二分搜索了。

和二分搜索不同的是，如果已有数组搜索不到这个数时，需要将target和搜索结果数进行比较，如果小于就插入在这个数的下标处，否则，插入位置在这个数下标向右偏移一位处。