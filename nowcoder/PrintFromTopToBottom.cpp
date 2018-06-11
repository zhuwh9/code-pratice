#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {
	}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    if (root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
		root = q.front();
        res.push_back(root->val);
        if (root->left != NULL) q.push(root->left);
        if (root->right != NULL) q.push(root->right);
        q.pop();
    }
    return res;
}

int main() {
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> res = PrintFromTopToBottom(root);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
	system("pause");
    return 0;
}
