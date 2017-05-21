/** 
 * Given an array of numbers nums, in which exactly two 
 * elements appear only once and all the other elements 
 * appear exactly twice. Find the two elements that appear only once.
 *
 * For example:
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 * Note:
 * The order of the target is not important. So in the above example, 
 * [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. 
 * Could you implement it using only constant space complexity?
 */

/* Failed */
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int target = 0;
    for (int i = 0; i < nums.size(); ++i)
      target ^= nums[i];
    /* get rightmost set bit */
    int index = target & (~(target - 1));
    vector<int> result(2, 0);
    for (auto num : nums) {
      if (num & index)
        result[0] ^= num;
      else
        result[1] ^= num;
    }
    return result;
  }
};