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
void pathSum(TreeNode * &node, vector<vector<int>> & result, vector<int> &t, int sum, int target) {
	if (node->left == NULL && node->right == NULL) {
		if (sum == target) {
			result.push_back(t);
		}
	}
	if (node->left != NULL) {
		t.push_back(node->left->val);
		pathSum(node->left, result, t, sum + node->left->val, target);
		t.pop_back();
	}
	if (node->right != NULL) {
		t.push_back(node->right->val);
		pathSum(node->right, result, t, sum + node->right->val, target);
		t.pop_back();
	}
}
vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
	vector<vector<int>> result;
	vector<int> t;
	if (root == NULL) {
		return result;
	}
	t.push_back(root->val);
	pathSum(root, result, t, root->val, target);
	return result;
}