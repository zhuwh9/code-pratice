class Solution {
public:
    int getNodeHeight(TreeNode* node, int depth) {
        if (node != NULL) {
            depth++;
            int left = getNodeHeight(node->left, depth);
            int right = getNodeHeight(node->right, depth);
            return left > right ? left : right;
        }
        return depth;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL)
            return true;
        else {
            int left = 0, right = 0;
            if (pRoot->left)
                left = getNodeHeight(pRoot->left, 0);
            if (pRoot->right)
                right = getNodeHeight(pRoot->right, 0);
            if (abs(left - right) <= 1) {
                return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
            } else {
                return false;
            }
        }
    }
};
