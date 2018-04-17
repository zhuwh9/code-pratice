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
void flatten(TreeNode * root) {
	if (root == NULL) {
		return;
	}
	if (root->left) flatten(root->left);
	if (root->right) flatten(root->right);
	TreeNode * right = root->right;
	root->right = root->left;
	root->left = NULL;
	while (root->right) {
		root = root->right;
	}
	root->right = right;
}