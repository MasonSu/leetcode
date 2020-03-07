// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<string> result;
        dfs(result, std::to_string(root->val), root);
        return result;
    }

private:
	// str这里没法用引用，因为32和3需要pop_back的次数是不一样的
    void dfs(vector<string>& result, string str, TreeNode* root) {
    	if (root->left == NULL && root->right == NULL) {
            result.push_back(str);
            return;
        }
        if (root->left)
        	dfs(result, str + "->" + std::to_string(root->left->val), root->left);
        if (root->right)
        	dfs(result, str + "->" + std::to_string(root->right->val), root->right);
    }
};