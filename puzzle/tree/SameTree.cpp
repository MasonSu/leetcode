// Given two binary trees, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical 
// and the nodes have the same value.

// Example 1:

// Input:     1         1
//           / \       / \
//          2   3     2   3

//         [1,2,3],   [1,2,3]

// Output: true

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return same(p, q);
    }
    
private:
    bool same(TreeNode *p, TreeNode *q) {
        if (p && q) {
            if (p->val == q->val) {
                return same(p->left, q->left) && same(p->right, q->right);
            } else {
                return false;
            }
        }
        return p == q;
    }
};