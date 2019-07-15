class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return commonAncestor(root, p, q);
    }
private:
    TreeNode* commonAncestor(TreeNode* root, TreeNode *p, TreeNode *q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* left = commonAncestor(root->left, p, q), *right = commonAncestor(root->right, p, q);
        if (left && right) 
            return root;
        return left != NULL ? left : right;
    }
};