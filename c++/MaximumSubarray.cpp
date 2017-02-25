/**
 *
 * Find the contiguous subarray within an array (containing at least one number) 
 * which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 */

/* Failed */
#include <vector>

using std::vector;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty())
      return 0;
    int global_max = nums[0], local_max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      local_max = local_max + nums[i] > nums[i] ? local_max + nums[i] : nums[i];
      global_max = global_max > local_max ? global_max : local_max;
    }
    return global_max;
  }
};