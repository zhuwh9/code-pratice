# 109. Triangle

## Description

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

**Notice**

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

## Example

Given the following triangle:

```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

## Analysis

动态规划题目，需要找到递归/迭代函数（状态转移函数），确定边界的转移（边界状态特殊处理）。

这里，显然是先从上一层邻接的两个位置所保存的最短路径加上当前点作为这个位置的最短路径，一直迭代到最后一层，然后遍历最后一层得到最小值，这就是最短路径长度。（也可以通过这个反向求得最短路径点集合。）

## Code

```c++
int minimumTotal(vector<vector<int> > &triangle) {
	if (triangle.size() == 0)
		return 0;

  	// reusable array to reserve last level min way value
	vector<int> f(triangle[triangle.size() - 1].size());
  
	f[0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = triangle[i].size() - 1; j >= 0; j--) {
			if (j == 0) {//only one min way
				f[j] = f[j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1) {//only one min way
				f[j] = f[j - 1] + triangle[i][j];
			}
			else {//find last level min way from two adjacent last level position
				f[j] = min(f[j - 1], f[j]) + triangle[i][j];
			}
		}
	}
  
	int ret = INT_MAX;
	for (int i = 0; i < f.size(); i++)
		ret = min(ret, f[i]);//find the shortest value
	return ret;
}
```

