// Given a set of distinct integers, nums, return all possible 
// subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<vector<int>> result;
        vector<int> vec;
        dfs(nums, result, vec, 0);
        return result;
    }

private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& vec, int begin) {
        result.push_back(vec);
        for (int i = begin; i < nums.size(); ++i) {
            vec.push_back(nums[i]);
            dfs(nums, result, vec, i + 1);
            vec.pop_back();
        }
    }
};