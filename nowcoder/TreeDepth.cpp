/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        return getNodeDepth(pRoot, 0);
    }
    int getNodeDepth(TreeNode* node, int depth) {
        if (node != NULL) {
            depth++;
            int left = getNodeDepth(node->left, depth);
            int right = getNodeDepth(node->right, depth);
            return left > right ? left : right;
        }
        return depth;
    }
};
