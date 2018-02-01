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
//non-recursive version
TreeNode * insertNode(TreeNode * root, TreeNode * node) {
	// write your code here
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
// recursive version
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
int main() {
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	TreeNode* toInsert = new TreeNode(3);
	TreeNode* result = insertNode(root, toInsert);
	return 0;
}