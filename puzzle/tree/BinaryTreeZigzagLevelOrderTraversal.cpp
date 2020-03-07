// Given a binary tree, return the zigzag level order traversal 
// of its nodes' values. (ie, from left to right, then right to 
// left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

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
                    // 从左往右扫描，新的节点插入到尾部
                    TreeNode* node = nodes.front();
                    nodes.pop_front();
                    vec.push_back(node->val);
                    if (node->left)
                        nodes.push_back(node->left);
                    if (node->right)
                        nodes.push_back(node->right);
                } else {
                    // 从右往左扫描，新的节点插入到头部
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