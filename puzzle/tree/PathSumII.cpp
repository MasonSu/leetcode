// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return {};
		vector<vector<int>> result;
		vector<int> vec;
		dfs(result, vec, root, sum);
		return result;
	}

private:
	void dfs(vector<vector<int>>& result, vector<int>& vec, TreeNode* root, int target) {
		if (root == NULL)
			return;

		vec.push_back(root->val);
		if (root->val == target && !root->left && !root->right) {
			result.push_back(vec);
			// 这步是必须的
			vec.pop_back();
			return;
		}

		dfs(result, vec, root->left, target - root->val);
		dfs(result, vec, root->right, target - root->val);
		vec.pop_back();
	}
};