## 64. Merge Sorted Array

## Description

Given two sorted integer arrays A and B, merge B into A as one sorted array.

##### **Notice** 

You may assume that A has enough space (size that is greater or equal to *m* + *n*) to hold additional elements from B. The number of elements initialized in A and B are *m* and *n* respectively.

## Example

A = `[1, 2, 3, empty, empty]`, B = `[4, 5]`

After merge, A will be filled as `[1, 2, 3, 4, 5]`

## Analysis

题目显然是想要我们利用已经排好序这个特点优化算法。

当然，为了避免Merge时产生性能上的浪费，直接往A中插入然后排序是很愚蠢的。

因此，应该先将A变成链表，然后查找合适的位置插入B的元素。

## Code

```c++
void mergeSortedArray(int A[], int m, int B[], int n) {
	// write your code here
	list<int> temp;
	for (int i = 0; i < m; i++) {
		temp.push_back(A[i]);
	}
	if (n == 0) {
		return;
	}
	if (m == n) {
		for (int i = 0; i < m; i++) {
			A[i] = B[i];
		}
		return;
	}
	// A and B both have elements
	list<int>::iterator itr_current = temp.begin();
	list<int>::iterator itr_last = --temp.end();
	int pos = 0;
	while (1) {
		if (itr_current != itr_last) {
			int current = *itr_current;
			itr_current++;
			int next = *itr_current;
			if (current <= B[pos] && B[pos] <= next) {
				itr_current = temp.insert(itr_current, B[pos]);
				pos++;
				if (pos >= n) {
					break;
				}
			}
			else if (B[pos] <= current) {
				itr_current--;
				itr_current = temp.insert(itr_current, B[pos]);
				pos++;
				if (pos >= n) {
					break;
				}
			}
		}
		else {
			while (pos < n) {
				temp.insert(temp.end(), B[pos]);
				pos++;
			}
			break;
		}
	}
	pos = 0;
	for (itr_current = temp.begin(); itr_current != temp.end(); itr_current++) {
		A[pos] = *itr_current;
		pos++;
	}
}
```