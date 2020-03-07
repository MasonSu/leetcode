// Given a set of candidate numbers (candidates) (without duplicates) and a 
// target number (target), find all unique combinations in candidates where 
// the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

/* 数组中不含有重复数字，每个数字可以被使用多次 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty())
            return {};
        vector<vector<int>> result;
        vector<int> vec;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, result, vec, target, 0);
        return result;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& result, vector<int>& vec, int target, int begin) {
        if (target == 0) {
            result.push_back(vec);
            return;
        }
        for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
            vec.push_back(candidates[i]);
            dfs(candidates, result, vec, target - candidates[i], i);
            vec.pop_back();
        }
    }
};