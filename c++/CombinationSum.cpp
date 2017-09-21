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
#include <iostream>
#include <algorithm>

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
      if (candidates[i] > target)
        break;
      vec.push_back(candidates[i]);
      backtracking(result, vec, candidates, target - candidates[i], i);
      vec.pop_back();
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<vector<int>> result;
  vector<int> vec{2, 3, 6, 7};
  result = test.combinationSum(vec, 7);
  for (const vector<int> vec : result) {
    for (const int i : vec)
      std::cout << i << ' ';
    std::cout << '\n';
  }
  return 0;
}