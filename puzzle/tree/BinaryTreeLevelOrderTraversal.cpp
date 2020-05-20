// Given a binary tree, return the level order traversal of its nodes'
// values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

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