// Given a collection of integers that might contain duplicates, 
// nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<vector<int>> result;
        vector<int> vec;
        std::sort(nums.begin(), nums.end());
        dfs(result, vec, nums, 0);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& result, vector<int>& vec, vector<int>& nums, int begin) {
        result.push_back(vec);
        for (int i = begin; i < nums.size(); ++i) {
        	// 这里是i > begin，不是i > 1
            if (i > begin && nums[i] == nums[i - 1])
                continue;
            vec.push_back(nums[i]);
            dfs(result, vec, nums, i + 1);
            vec.pop_back();
        }
    }
};