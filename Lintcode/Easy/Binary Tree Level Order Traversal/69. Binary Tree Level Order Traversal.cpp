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
vector<vector<int>> levelOrder(TreeNode * root) {
	// write your code here
	vector<vector<int>> result;
	if (root == NULL) {
		return result;
	}
	queue<TreeNode*> main_queue;
	main_queue.push(root);
	while (main_queue.empty() == false) {
		vector<int> temp;
		int len = main_queue.size();
		for (int i = 0; i < len; i++) {
			temp.push_back(main_queue.front()->val);
			if (main_queue.front()->left != NULL) {
				main_queue.push(main_queue.front()->left);
			}
			if (main_queue.front()->right != NULL) {
				main_queue.push(main_queue.front()->right);
			}
			main_queue.pop();
		}
		result.push_back(temp);
	}
	return result;
}