class Solution {
private:
    bool isSubtree(TreeNode* node1, TreeNode* node2) {
        if (node2 == NULL) return true;
        if (node1 == NULL) return false;
        if (node2->val == node1->val) {
            return isSubtree(node1->left, node2->left) && isSubtree(node1->right, node2->right);
        } else {
            return false;
        }
    }
public:
    bool HasSubtree(TreeNode* node1, TreeNode* node2)
    {
        if (node1 == NULL || node2 == NULL) return false;
        return isSubtree(node1, node2) || HasSubtree(node1->left, node2) || HasSubtree(node1->right, node2);
    }
};
