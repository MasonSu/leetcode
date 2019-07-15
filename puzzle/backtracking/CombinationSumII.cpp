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