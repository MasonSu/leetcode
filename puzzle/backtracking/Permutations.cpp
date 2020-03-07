// Given a collection of distinct integers, return all 
// possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<vector<int>> result;
        dfs(result, nums, 0);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& result, vector<int>& nums, int begin) {
        if (begin == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            std::swap(nums[begin], nums[i]);
            // 这里是begin + 1
            dfs(result, nums, begin + 1);
            std::swap(nums[begin], nums[i]);
        }
    }
};