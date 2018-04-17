#include<iostream>
#include<vector>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int getDepth(TreeNode* node) {
	if (node == NULL)
		return 0;
	int left_tree_depth = getDepth(node->left);
	int right_tree_depth = getDepth(node->right);
	return left_tree_depth > right_tree_depth ? (left_tree_depth+1): (right_tree_depth+1);
}
bool isBalanced(TreeNode * root) {
	// write your code here
	if (root == NULL) {
		return true;
	}
	if (abs(getDepth(root->left) - getDepth(root->right)) > 1) {
		return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);
}