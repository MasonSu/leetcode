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
			vec.pop_back();
			return;
		}

		dfs(result, vec, root->left, target - root->val);
		dfs(result, vec, root->right, target - root->val);
		vec.pop_back();
	}
};