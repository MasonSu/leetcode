class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (nodes.size()) {
            int num = nodes.size();
            vector<int> vec;
            while (num--) {
                TreeNode* node = nodes.front();
                nodes.pop();
                vec.push_back(node->val);
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};