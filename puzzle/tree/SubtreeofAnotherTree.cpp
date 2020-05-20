// Given two non-empty binary trees s and t, check whether tree t has exactly the 
// same structure and node values with a subtree of s. A subtree of s is a tree 
// consists of a node in s and all of this node's descendants. The tree s could 
// also be considered as a subtree of itself.

// Example 1:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4 
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.
// Example 2:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == NULL)
            return true;
        bool result = false;
        preOrder(s, t, result);
        return result;        
    }
private:
    void preOrder(TreeNode* root, TreeNode* t, bool& result) {
        if (root == NULL || result)
            return;
        if (root->val == t->val)
            result = sameTree(root, t);
        preOrder(root->left, t, result);
        preOrder(root->right, t, result);
    }
    
    bool sameTree(TreeNode* node1, TreeNode* node2) {
        if (node1 && node2)
            return node1->val == node2->val && sameTree(node1->left, node2->left) && 
                    sameTree(node1->right, node2->right);
        else
            return node1 == node2;
    }
};