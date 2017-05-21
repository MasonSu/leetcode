/**
 * You are a professional robber planning to rob houses
 * along a street. Each house has a certain amount of
 * money stashed, the only constraint stopping you from
 * robbing each of them is that adjacent houses have
 * security system connected and it will automatically
 * contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given a list of non-negative integers representing the
 * amount of money of each house, determine the maximum
 * amount of money you can rob tonight without alerting the police.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty())
      return 0;
    if (nums.size() == 1)
      return nums[0];
    int size = nums.size();
    vector<int> vec(size, 0);
    vec[0] = nums[0], vec[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < size; ++i)
      vec[i] = std::max(vec[i - 2] + nums[i], vec[i - 1]);    
    return vec.back();
  }
};