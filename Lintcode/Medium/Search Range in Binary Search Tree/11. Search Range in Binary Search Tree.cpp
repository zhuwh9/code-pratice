#include<iostream>
#include<string>
#include<vector>
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
vector<int> searchRange(TreeNode * root, int k1, int k2) {
	vector<int> result;
	if (root == NULL) {
		return result;
	}
	queue<TreeNode*> root_queue;
	root_queue.push(root);
	while (root_queue.empty() == false) {
		TreeNode* node = root_queue.front();
		root_queue.pop();
		if (node->left != NULL)
			root_queue.push(node->left);
		if (node->right != NULL)
			root_queue.push(node->right);
		if (node->val >= k1 && node->val <= k2) {
			result.push_back(node->val);
		}
	}
	int size = result.size();
	for (int i = 0; i < size - 1; i++) {
		bool isChanged = true;
		for (int j = 0; j < size - 1; j++) {
			if (result[j] > result[j + 1]) {
				int temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
				isChanged = false;
			}
		}
		if (isChanged) {
			break;
		}
	}
	return result;
}
int main() {
	TreeNode * root = new TreeNode(5);
	/*root->left = new TreeNode(8);
	root->right = new TreeNode(22);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(12);*/
	int k1 = 6, k2 = 10;
	vector<int> result = searchRange(root, k1, k2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}