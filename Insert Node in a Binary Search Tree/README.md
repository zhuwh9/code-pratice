# 85. Insert Node in a Binary Search Tree

## Description

Given a binary search tree and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.

## Example

Given binary search tree as follow, after Insert node 6, the tree should be:

```
  2             2
 / \           / \
1   4   -->   1   4
   /             / \ 
  3             3   6
```

## Challenge

Can you do it without recursion?

## Analysis

显然可以通过两种方式（递归，迭代）插入

### 递归

这里还是遇到了坑，insert函数传入参数必须加TreeNode*必须加引用，否则指针指向不同内存地址，导致插入失败：

```c++
void insert(TreeNode*& node, int val) {
	if (node == NULL) {
		node = new TreeNode(val);
		return;
	}
	else if (val < node->val) {
		insert(node->left, val);
	}
	else if (val > node->val) {
		insert(node->right, val);
	}
	else {

	}
}
TreeNode * insertNode(TreeNode * root, TreeNode * node) {
	if (node == NULL) {
		return root;
	}
	if (root == NULL) {
		return node;
	}
	TreeNode * temp = root;
	insert(temp, node->val);
	return temp;
}
```

### 迭代

```c++
TreeNode * insertNode(TreeNode * root, TreeNode * node) {
	if (node == NULL) {
		return root;
	}
	if (root == NULL) {
		return node;
	}
	TreeNode* to_insert = root;
	TreeNode* temp_head = to_insert;
	while (1) {
		int value = to_insert->val;
		if (to_insert->val < node->val) {
			if (to_insert->right != NULL) {
				to_insert = to_insert->right;
			}
			else if (to_insert->right == NULL) {
				to_insert->right = node;
				break;
			}

		}
		else if (node->val <= to_insert->val) {
			if (to_insert->left != NULL) {
				to_insert = to_insert->left;
			}
			else if (to_insert->left == NULL) {
				to_insert->left = node;
				break;
			}
		}
	}
	return temp_head;
}
```

