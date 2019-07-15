/* 这种方法使用INT_MIN，需要考虑的条件更多，不合适 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        int num = 0;
        bool first = true;
        stack<TreeNode*> nodes;
        while (root || nodes.size()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                TreeNode* node = nodes.top();
                nodes.pop();
                if (first) {
                    first = false;
                } else if (node->val <= num) {
                    return false;
                }
                num = node->val;
                root = node->right;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        stack<TreeNode*> nodes;
        TreeNode* prev = NULL;
        while (root || nodes.size()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                TreeNode *node = nodes.top();
                nodes.pop();
                if (prev != NULL && node->val <= prev->val)
                    return false;
                prev = node;
                root = node->right;
            }
        }
        return true;
    }
};