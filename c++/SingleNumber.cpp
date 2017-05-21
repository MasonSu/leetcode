/**
 * Given an array of integers, every element appears twice except
 * for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/*class Solution {
public:
  int singleNumber(vector<int>& nums) {
    if (nums.size() == 1)
      return nums[0];
    std::sort(nums.begin(), nums.end());
    auto iter = nums.begin();
    for (;iter != nums.end() - 1; iter += 2)
      if (*iter != *(iter + 1))
        return *iter;
    return *iter;
  }
};*/

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i)
      result ^= nums[i];
    return result;
  }
};