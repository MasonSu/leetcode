// Given a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (nodes.size()) {
            result.push_back(nodes.back()->val);
            int num = nodes.size();
            for (int i = 0; i < num; ++i) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
            }
        }
        return result;
    }
};