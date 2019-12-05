// Given a binary tree, return the postorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [3,2,1]
// Follow up: Recursive solution is trivial, could you do it iteratively?

class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
private:
    void postorder(TreeNode* root, vector<int>& vec) {
        if (root == NULL)
            return;
        postorder(root->left, vec);
        postorder(root->right, vec);
        vec.push_back(root->val);
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> result;
        stack<TreeNode*> nodes1, nodes2;
        while (root || nodes1.size()) {
            if (root) {
                nodes1.push(root);
                root = root->left;
            } else {
                TreeNode* node = nodes1.top();
                if (nodes2.size() && node == nodes2.top()) {
                    result.push_back(node->val);
                    nodes1.pop();
                    nodes2.pop();
                    continue;
                }
                if (node->right) {
                    nodes2.push(node);
                    root = node->right;
                } else {
                    result.push_back(node->val);
                    nodes1.pop();
                }
            }
        }
        return result;
    }
};

class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<int> result;
        stack<TreeNode*> nodes;
        while (root || nodes.size()) {
            if (root) {
                result.push_back(root->val);
                nodes.push(root);
                root = root->right;
            } else {
                TreeNode* node = nodes.top();
                nodes.pop();
                root = node->left;
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};