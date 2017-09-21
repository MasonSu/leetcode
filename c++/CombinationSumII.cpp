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

/* Failed */
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> vec;

    std::sort(candidates.begin(), candidates.end());
    backtracking(result, vec, candidates, target, 0);

    return result;
  }

private:
  void backtracking(vector<vector<int>>& result, vector<int>& vec, vector<int>& candidates, int target, int begin) {
    if (target == 0) {
      result.push_back(vec);
      return;
    }

    for (int i = begin; i < candidates.size(); ++i) {
      /* 这步用来去重，很关键 */
      if (i > begin && candidates[i] == candidates[i - 1])
        continue;

      if (candidates[i] > target)
        break;
      vec.push_back(candidates[i]);
      backtracking(result, vec, candidates, target - candidates[i], i + 1);
      vec.pop_back();
    }
  }
};