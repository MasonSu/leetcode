/** 
 * Given an array of integers, every element appears three times 
 * except for one, which appears exactly once. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you 
 * implement it without using extra memory?
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
    for(;iter != nums.end() - 1; iter += 3)
      if (*iter != *(iter + 1) || *iter != *(iter + 2))
        return *iter;
    return *iter;
  }
};*/

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < sizeof(int) * 8; ++i) {
      int sum = 0;
      for (int j = 0; j < nums.size(); ++j)
        sum += (nums[j] >> i) & 1;
      result |= (sum % 3) << i;
    }
    return result;
  }
};