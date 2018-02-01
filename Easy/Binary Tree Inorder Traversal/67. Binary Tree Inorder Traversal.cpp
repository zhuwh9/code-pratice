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
vector<int> inorderTraversal(TreeNode * root) {
	// write your code here
	vector<int> result;
	if (root != NULL) {
		vector<int> result1 = inorderTraversal(root->left);
		for (int i = 0; i < result1.size(); i++) {
			result.push_back(result1[i]);
		}
		result.push_back(root->val);
		vector<int> result2 = inorderTraversal(root->right);
		for (int i = 0; i < result2.size(); i++) {
			result.push_back(result2[i]);
		}
	}
	return result;
}