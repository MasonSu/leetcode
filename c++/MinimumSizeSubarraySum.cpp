/**
 * Given an array of n positive integers and a positive integer s,
 * find the minimal length of a contiguous subarray of which the
 * sum ? s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 */

#include <vector>

using std::vector;

/* Equal */
/*class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int sum = 0, length = 0, first = -1, second = -1;

    while (1) {
      if (second == nums.size() - 1 && sum < s)
        break;

      if (sum == s) {
        if (length == 0 || second - first < length)
          length = second - first;
        if (second == nums.size() - 1)
          break;

        first++;
        sum -= nums[first];
        second++;
        sum += nums[second];
      } else if (sum < s) {
        second++;
        sum += nums[second];
      } else {
        first++;
        sum -= nums[first];
      }
    }

    return length;
  }
};*/

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int sum = 0, length = 0, first = -1, second = -1;

    while (1) {
      if (second == nums.size() - 1 && sum < s)
        break;

      if (sum < s) {
        second++;
        sum += nums[second];
      } else {
        if (length == 0 || second - first < length)
          length = second - first;
        first++;
        sum -= nums[first];
      }
    }

    return length;
  }
};