class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> result;
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        bool flag = true;
        while (nodes.size()) {
            vector<int> vec;
            int num = nodes.size();
            while (num--) {
                if (flag) {
                    TreeNode* node = nodes.front();
                    nodes.pop_front();
                    vec.push_back(node->val);
                    if (node->left)
                        nodes.push_back(node->left);
                    if (node->right)
                        nodes.push_back(node->right);
                } else {
                    TreeNode* node = nodes.back();
                    nodes.pop_back();
                    vec.push_back(node->val);
                    if (node->right)
                        nodes.push_front(node->right);
                    if (node->left)
                        nodes.push_front(node->left);
                }
            }
            flag = !flag;
            result.push_back(vec);
        }
        return result;
    }
};