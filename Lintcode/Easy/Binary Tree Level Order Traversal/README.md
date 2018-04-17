# 69. Binary Tree Level Order Traversal

## Description

Given a binary tree, return the *level order* traversal of its nodes' values. (ie, from left to right, level by level).

## Example

Given binary tree `{3,9,20,#,#,15,7}`,

```
    3
   / \
  9  20
    /  \
   15   7
```

 

return its level order traversal as:

```
[
  [3],
  [9,20],
  [15,7]
]
```

## Challenge

Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use DFS algorithm to do it.

## Analysis

广度优先遍历：利用queue的特性，在将队列首部的pop以后，将队列首部的左右子节点加入到队列尾部。

需要注意的点是，返回结果里，每一层广度遍历的结果单独保存在一个`vector<int>`里，然后用一个`vector<vector<int>>`保存所有层的`vector<int>`。

因此，每一轮需要先保存队列的长度`len`，然后再弹出`len`次队列头（每个队列头的`val`保存在`vector<int>`中），并将该队列头的左右非空子节点（`left`和`right` ）加入队列。（利用`len`进行限制，使得这些新加的子节点不会在当前轮中遍历）

当某一轮队列为空时，停止遍历。

## Code

```c++
vector<vector<int>> levelOrder(TreeNode * root) {
	// write your code here
	vector<vector<int>> result;
	if (root == NULL) {
		return result;
	}
	queue<TreeNode*> main_queue;
	main_queue.push(root);
	while (main_queue.empty() == false) {
		vector<int> temp;
		int len = main_queue.size();
		for (int i = 0; i < len; i++) {
			temp.push_back(main_queue.front()->val);
			if (main_queue.front()->left != NULL) {
				main_queue.push(main_queue.front()->left);
			}
			if (main_queue.front()->right != NULL) {
				main_queue.push(main_queue.front()->right);
			}
			main_queue.pop();
		}
		result.push_back(temp);
	}
	return result;
}
```

