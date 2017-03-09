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
#include <iostream>
#include <algorithm>

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> tmp;
    std::sort(candidates.begin(), candidates.end());
    combination(result, tmp, candidates, 0, target, 0);
    return result;
  }

private:
  void combination(vector<vector<int>>& result, vector<int>& tmp, const vector<int>& candidates, int sum, int target, int begin) {
    if (sum == target) {
      result.push_back(tmp);
      return;
    }
    for (int i = begin; i < candidates.size(); ++i) {
      if (i > begin && candidates[i] == candidates[i - 1])
        continue;
      if (sum + candidates[i] <= target) {
        tmp.push_back(candidates[i]);
        combination(result, tmp, candidates, sum + candidates[i], target, i + 1);
        tmp.pop_back();
      }
    }
  }
};