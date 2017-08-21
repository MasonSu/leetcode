/**
 * Given an array of n integers where n > 1, nums, return
 * an array output such that output[i] is equal to the
 * product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity?
 * (Note: The output array does not count as extra space
 * for the purpose of space complexity analysis.)
 */


#include <iostream>
#include <vector>

using std::vector;

/*class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty())
      return {};

    int product = 1, count = 0, index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        count++;
        index = i;
      } else {
        product *= nums[i];
      }
    }

    vector<int> result(nums.size());
    if (count > 1)
      return result;
    else if (count == 1) {
      result[index] = product;
      return result;
    }

    for (int i = 0; i < nums.size(); ++i)
      result[i] = product / nums[i];

    return result;
  }
};*/

/* 每个位置等于它左边所有数的乘积再乘上右边所有数的乘积 */
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size());
    int product = 1;
    /* from left to right */
    for (int i = 0; i < nums.size(); ++i) {
      result[i] = product;
      product *= nums[i];
    }

    product = 1;
    /* from right to left */
    for (int i = nums.size() - 1; i >= 0; --i) {
      result[i] *= product;
      product *= nums[i];
    }

    return result;
  }
};