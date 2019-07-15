class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        depth(root, max);
        return max;
    }
private:
    int depth(TreeNode* root, int& max) {
        if (root == NULL)
            return -1;
        int leftDepth = 1 + depth(root->left, max), rightDepth = 1 + depth(root->right, max);
        if (leftDepth + rightDepth > max)
            max = leftDepth + rightDepth;
        return std::max(leftDepth, rightDepth);
    }
};