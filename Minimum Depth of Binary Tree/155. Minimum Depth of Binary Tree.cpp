#include<iostream>
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