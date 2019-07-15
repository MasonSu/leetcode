/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
private:
    void preorder(TreeNode* root, vector<int>& vec) {
        if (root == NULL)
            return;
        vec.push_back(root->val);
        preorder(root->left, vec);
        preorder(root->right, vec);
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> result;
        stack<TreeNode*> nodes;
        while (root || nodes.size()) {
            if (root) {
                result.push_back(root->val);
                nodes.push(root);
                root = root->left;
            } else {
                TreeNode *node = nodes.top();
                nodes.pop();
                root = node->right;
            }
        }
        return result;
    }
};