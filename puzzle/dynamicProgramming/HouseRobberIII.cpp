// The thief has found himself a new place for his thievery again. There 
// is only one entrance to this area, called the "root." Besides the root,
// each house has one and only one parent house. After a tour, the smart 
// thief realized that "all houses in this place forms a binary tree". 
// It will automatically contact the police if two directly-linked houses 
// were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without
// alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

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