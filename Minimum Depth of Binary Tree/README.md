# 155. Minimum Depth of Binary Tree

## Description

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

## Example

Given a binary tree as follow:

```
  1
 / \ 
2   3
   / \
  4   5
```

The minimum depth is `2`.

## Analysis

需要考虑不存在叶子节点的情况

## Code

```c++
int minDepth(TreeNode * root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL) {
		return minDepth(root->right) + 1;
	}
	if (root->right == NULL) {
		return minDepth(root->left) + 1;
	}
	int left = minDepth(root->left);
	int right = minDepth(root->right);
	return left > right ? (right + 1) : (left + 1);
}
```

