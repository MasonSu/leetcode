// You are given a binary tree in which each node contains an integer value.

// Find the number of paths that sum to a given value.

// The path does not need to start or end at the root or a leaf, but it must go 
// downwards (traveling only from parent nodes to child nodes).

// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 
// to 1,000,000.

// Example:

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        unordered_map<int, int> pre_sum;
        // 这步操作不能少，否则结果会少一些值
        pre_sum[0] = 1;
        int result = 0;
        dfs(root, sum, 0, pre_sum, result);
        return result;
    }

private:
	// pre_sum引用可以减少运行时间和内存
    void dfs(TreeNode* root, int target, int sum, unordered_map<int, int>& pre_sum, int& result) {
        if (root == NULL)
            return;
        sum += root->val;
        if (pre_sum.count(sum - target) != 0)
            result += pre_sum[sum - target];
        pre_sum[sum]++;
        dfs(root->left, target, sum, pre_sum, result);
        dfs(root->right, target, sum, pre_sum, result);
        pre_sum[sum]--;
    }
};