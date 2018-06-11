#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {
	}
};

void dfs(TreeNode* node, int target, vector< vector<int> > &res, vector<int> &trace) {
	trace.push_back(node->val);
	if (!node->left && !node->right) {
		if (target == node->val) {
			res.push_back(trace);
		}
	}
	if (node->left) {
		dfs(node->left, target - node->val, res, trace);
	}
	if (node->right) {
		dfs(node->right, target - node->val, res, trace);
	}
	trace.pop_back();
}

vector< vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector< vector<int> > res;
	vector<int> trace;
	if (root) {
		dfs(root, expectNumber, res, trace);
	}
	return res;
}
