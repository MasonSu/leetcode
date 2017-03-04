/**
 *
 * Given a set of candidate numbers (C) (without duplicates)
 * and a target number (T), find all unique combinations in C
 * where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7,
 * A solution set is:
 * [
 *   [7],
 *   [2, 2, 3]
 * ]
 *
 */

/* Failed */
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty())
      return {};
    vector<vector<int>> result;
    vector<int> combin;
    std::sort(candidates.begin(), candidates.end());
    combination(result, combin, candidates, target, 0);
    return result;
  }

private:
  void combination(vector<vector<int>>& result, vector<int>& combin, const vector<int>& candidates, int target, int begin) {
    if (target == 0) {
      result.push_back(combin);
      return;
    }
    for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
      combin.push_back(candidates[i]);
      combination(result, combin, candidates, target - candidates[i], i);
      combin.pop_back();
    }
  }
};

