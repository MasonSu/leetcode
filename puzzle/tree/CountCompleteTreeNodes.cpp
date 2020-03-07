// Given a complete binary tree, count the number of nodes.

// Note:

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, 
// is completely filled, and all nodes in the last level are as far 
// left as possible. It can have between 1 and 2h nodes inclusive 
// at the last level h.

// Example:

// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6

class Solution {
public:
    int countNodes(TreeNode* root) {
        int ld = leftdepth(root), rd = rightdepth(root);
        if (ld == rd)
            return (1 << ld) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
private:
    int leftdepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int count = 1;
        while (root->left) {
            count++;
            root = root->left;
        }
        return count;
    }
    
    int rightdepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int count = 1;
        while (root->right) {
            count++;
            root = root->right;
        }
        return count;
    }
};