/** 
 * Given a collection of numbers that might contain 
 * duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 *
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */

/* Failed */
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    if (nums.empty())
      return {};

    vector<vector<int>> result;
    vector<int> used(nums.size()), vec;
    std::sort(nums.begin(), nums.end());

    backtracking(result, vec, used, nums);

    return result;
  }

private:
  void backtracking(vector<vector<int>>& result, vector<int>& vec, vector<int>& used, vector<int>& nums) {
    if (vec.size() == nums.size()) {
      result.push_back(vec);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;
      /* 对于和前一个数相等，并且前一个数没有被使用的话，不要放入递归 */
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
        continue;
      used[i] = true;
      vec.push_back(nums[i]);
      backtracking(result, vec, used, nums);
      vec.pop_back();
      used[i] = false;
    }
  }
};