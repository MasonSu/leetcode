/** 
 * Given a set of distinct integers, nums, return all 
 * possible subsets.
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,3], a solution is:
 * [
 *  [3],
 *  [1],
 *  [2],
 *  [1,2,3],
 *  [1,3],
 *  [2,3],
 *  [1,2],
 *  []
 * ]
 */

/* Failed */
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) 
      return {};

    vector<vector<int>> result;
    vector<int> vec;

    backtracking(result, vec, nums, 0);

    return result;
  }

private:
  void backtracking(vector<vector<int>>& result, vector<int>& vec, vector<int>& nums, int begin) {
    result.push_back(vec);

    for (int i = begin; i < nums.size(); ++i) {
      vec.push_back(nums[i]);
      backtracking(result, vec, nums, i + 1);
      vec.pop_back();
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> vec{1,2,3};
  vector<vector<int>> result = test.subsets(vec);
  for (auto v : result) {
    for (auto c : v)
      cout << c << " ";
    cout << "\n";
  }
  return 0;
}