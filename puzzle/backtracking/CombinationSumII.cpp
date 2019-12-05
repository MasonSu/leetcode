// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

/* 数组中含有重复数字，每个数字只能使用一次 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (i > begin && candidates[i] == candidates[i - 1])
                continue;
            vec.push_back(candidates[i]);
            dfs(candidates, result, vec, target - candidates[i], i + 1);
            vec.pop_back();
        }
    }
};