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
TreeNode * generateBST(int left, int right, vector<int> &A) {
	if (left > right) {
		return NULL;
	}
	else if (left == right) {
		return new TreeNode(A[left]);
	}
	else {
		int mid = (left + right) / 2;
		TreeNode * node = new TreeNode(A[mid]);
		node->left = generateBST(left, mid - 1, A);
		node->right = generateBST(mid + 1, right, A);
		return node;
	}
}
TreeNode * sortedArrayToBST(vector<int> &A) {
	return generateBST(0, A.size() - 1, A);
}