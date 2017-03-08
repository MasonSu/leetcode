/**
 *
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 *
 */

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (candidates.empty())
      return {};
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combin;
    combination(result, combin, candidates, target, 0);
    return result;
  }

private:
  void combination(vector<vector<int>>& result, vector<int>& combin, const vector<int>& candidates, int target, int begin) {
    if (target == 0) {
      if (std::find(result.begin(), result.end(), combin) == result.end())
        result.push_back(combin);
      return;
    }

    for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
      combin.push_back(candidates[i]);
      combination(result, combin, candidates, target - candidates[i], i + 1);
      combin.pop_back();
    }
  }
};