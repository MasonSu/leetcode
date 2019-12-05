// Given a binary tree, return the inorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
private:
    void inorder(TreeNode* root, vector<int>& vec) {
        if (root == NULL)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> result;
        stack<TreeNode*> nodes;
        while (root || nodes.size()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                TreeNode *node = nodes.top();
                nodes.pop();
                result.push_back(node->val);
                root = node->right;
            }
        }
        return result;
    }
};