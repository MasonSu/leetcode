class Solution {
public:
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        vector<int> result = dfs(root);
        return std::max(result[0], result[1]);
    }
private:
    /* dfs返回两个值，第一个值为选择当前点所能取得的
     * 最大值，第二个值为不选择当前点所能取得的最大值
     */
    vector<int> dfs(TreeNode* root) {
        if (root == NULL)
            return {0,0};
        vector<int> left = dfs(root->left), right = dfs(root->right);
        return {root->val + left[1] + right[1], std::max(left[0], left[1]) + std::max(right[0], right[1])};
    }
};