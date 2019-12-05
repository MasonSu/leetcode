// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

//  

// Example 1:

// Given the following tree [3,9,20,null,null,15,7]:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.

// Example 2:

// Given the following tree [1,2,2,3,3,null,null,4,4]:

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

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