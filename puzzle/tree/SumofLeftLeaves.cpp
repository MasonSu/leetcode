// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 
// 9 and 15 respectively. Return 24.

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        int result = 0;
        sum(root, false, result);
        return result;
    }

private:
    void sum(TreeNode* root, bool left, int& result) {
        if (root == NULL)
            return;
        if (left && root->left == NULL && root->right == NULL) {
            result += root->val;
            return;
        }
        sum(root->left, true, result);
        sum(root->right, false, result);
    }
};