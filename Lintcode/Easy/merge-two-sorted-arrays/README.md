# 6. Merge Two Sorted Arrays

## Description

Merge two given sorted integer array *A* and *B* into a new sorted integer array.

## Example

A=`[1,2,3,4]`

B=`[2,4,5,6]`

return `[1,2,2,3,4,4,5,6]`

##  分析

题目已知2个数组已经排好序，只需要分别用游标指向A，B的第一个数，如果A中游标所指的数小于B中游标所指的数，将A当前游标所指的数加进结果数组，然后A的游标向后移动一位；B的情况类似。

很容易看出，只需要若干次比较，就可以得到结果，不需要循环。
