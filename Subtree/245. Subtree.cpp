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
bool isSame(TreeNode * t1, TreeNode * t2) {
	if (t1 == NULL && t2 == NULL) {
		return true;
	}
	else if (t1 != NULL && t2 == NULL) {
		return false;
	}
	else if (t1 == NULL && t2 != NULL) {
		return false;
	}
	else {
		if (t1->val == t2->val) {
			return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
		}
		else {
			return false;
		}
	}
}
bool isSubtree(TreeNode * T1, TreeNode * T2) {
	if (T1 == NULL && T2 == NULL)
		return true;
	if (T1 == NULL)
		return false;
	if (T2 == NULL)
		return true;
	if (isSame(T1, T2))
		return true;
	return (isSubtree(T1->left, T2) || isSubtree(T1->right, T2));
}