/**
 * Given a sorted array consisting of only integers where
 * every element appears twice except for one element which
 * appears once. Find this single element that appears only once.
 *
 * Example 1:
 *
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 *
 * Example 2:
 *
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 *
 * Note: Your solution should run in O(log n) time and O(1) space.
 */

/* 加1，减2，多试几次才知道 */
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1)
      return nums[0];

    int start = 0, end = nums.size() - 1;
    while (start < end) {
      int middle = start + (end - start) / 2;
      if (nums[middle] != nums[middle - 1] && nums[middle] != nums[middle + 1])
        return nums[middle];

      if (nums[middle] == nums[middle - 1]) {
        if ((middle - start - 1) % 2)
          end = middle - 2;
        else
          start = middle + 1;
      } else if (nums[middle] == nums[middle + 1]) {
        if ((end - middle - 1) % 2)
          start = middle + 2;
        else
          end = middle - 1;
      }
    }

    return nums[start];
  }
};