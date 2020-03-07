// Given a binary tree containing digits from 0-9 only, each 
// root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents 
// the number 123.

// Find the total sum of all root-to-leaf numbers.

// Note: A leaf is a node with no children.

// Example:

// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = 0, num = 0;
        sum(root, result, num);
        return result;
    }
    
private:
    void sum(TreeNode* root, int& result, int num) {
        if (root == NULL)
            return;
        int s = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            result += s;
            return;
        }
        sum(root->left, result, s);
        sum(root->right, result, s);
    }
};