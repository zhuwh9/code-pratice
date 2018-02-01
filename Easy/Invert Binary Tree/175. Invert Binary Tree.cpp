#include<iostream>
#include<queue>
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
void invertBinaryTree(TreeNode * root) {
	if (root == NULL) {
		return;
	}
	TreeNode * t = root->left;
	root->left = root->right;
	root->right = t;
	invertBinaryTree(root->left);
	invertBinaryTree(root->right);
}