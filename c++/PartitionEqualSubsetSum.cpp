/**
 * Given a non-empty array containing only positive integers,
 * find if the array can be partitioned into two subsets such
 * that the sum of elements in both subsets is equal.
 *
 * Note:
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 * Example 2:
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 */

/* Failed */
#include <vector>
#include <iostream>

using std::vector;

/* Time Limit Exceeded */
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() == 1)
      return false;

    int sum = 0;
    for (auto i : nums)
      sum += i;

    if (sum % 2)
      return false;

    int target = sum / 2;

    return subSum(nums, nums.size() - 1, target);
  }

private:
  bool subSum(vector<int>& nums, int index, int target) {
    if (target == nums[index])
      return true;

    if (index == 0 && target != nums[index])
      return false;

    if (nums[index] > target)
      return subSum(nums, index - 1, target);

    return subSum(nums, index - 1, target) || subSum(nums, index - 1, target - nums[index]);
  }
};

class Solution2 {
public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() == 1)
      return false;

    int sum = 0;
    for (auto i : nums)
      sum += i;

    if (sum % 2)
      return false;

    int target = sum / 2;

    vector<int> result(target + 1);
    result[0] = 1;

    // 如果是这样的话，数字会被重复利用
    /*for (int i = 0; i < nums.size(); ++i)
      for (int j = 1; j <= target; ++j)
        if (nums[i] <= j)
          result[j] = result[j] | result[j - nums[i]];*/

    for (int i = 0; i < nums.size(); ++i)
      for (int j = target; j > 0; --j)
        if (nums[i] <= j)
          result[j] = result[j] | result[j - nums[i]];

    return result[target];
  }
};