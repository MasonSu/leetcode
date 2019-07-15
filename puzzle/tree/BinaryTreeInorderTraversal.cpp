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