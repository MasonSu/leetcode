/**
 * Given a collection of distinct numbers, return all
 * possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 *
 * [
 *  [1,2,3],
 *  [1,3,2],
 *  [2,1,3],
 *  [2,3,1],
 *  [3,1,2],
 *  [3,2,1]
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

/*class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty())
      return {};

    vector<vector<int>> result;

    backtracking(result, nums, 0);

    return result;
  }

private:
  void backtracking(vector<vector<int>>& result, vector<int>& nums, int begin) {
    cout << "begin is " << begin << ": ";
    for (auto i : nums)
      cout << i << " ";
    cout << "\n";

    if (begin == nums.size()) {
      result.push_back(nums);
      return;
    }

    for (int i = begin; i < nums.size(); ++i) {
      std::swap(nums[i], nums[begin]);
      backtracking(result, nums, begin + 1);
      std::swap(nums[i], nums[begin]);
    }
  }
};
*/

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty())
      return {};

    vector<vector<int>> result;
    vector<int> used(nums.size()), vec;
    backtracking(result, vec, used, nums);

    return result;
  }

private:
  void backtracking(vector<vector<int>>& result, vector<int>& vec, vector<int>& used, vector<int>& nums) {
    for (auto c : vec)
      cout << c << " ";
    cout << "\n";

    if (vec.size() == nums.size()) {
      result.push_back(vec);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;

      used[i] = 1;
      vec.push_back(nums[i]);
      backtracking(result, vec, used, nums);
      vec.pop_back();
      used[i] = 0;
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> nums{1, 2, 3};
  vector<vector<int>> result = test.permute(nums);

  cout << "\nresult\n";
  for (auto v : result) {
    for (auto c : v)
      cout << c << " ";
    cout << "\n";
  }
  return 0;
}