// Given a binary tree, check whether it is a mirror of itself 
// (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
 

// But the following [1,2,2,null,3,null,3] is not:

//     1
//    / \
//   2   2
//    \   \
//    3    3

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return symmetric(root->left, root->right);
    }
    
private:
    bool symmetric(TreeNode* p, TreeNode* q) {
        if (p && q) {
            if (p->val == q->val) {
                return symmetric(p->left, q->right) && symmetric(p->right, q->left);
            } else {
                return false;
            }
        }
        return p == q;
    }
};