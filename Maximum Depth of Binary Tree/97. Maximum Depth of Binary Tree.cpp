#include<iostream>
#include<queue>
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
int maxDepth(TreeNode *root) {
	// write your code here
	if (root == NULL) {
		return 0;
	}
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);
	return left > right ? (left+1) : (right+1);
}