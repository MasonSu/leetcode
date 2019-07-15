class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
private:
    int depth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftDepth = 1 + depth(root->left), rightDepth = 1 + depth(root->right);
        if (leftDepth == 0 || rightDepth == 0 || std::abs(leftDepth - rightDepth) > 1)
            return -1;
        else
            return std::max(leftDepth, rightDepth);
    }
};