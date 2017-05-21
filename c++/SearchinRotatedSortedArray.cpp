/**
 *
 * Suppose an array sorted in ascending order is rotated at some pivot 
 * unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, 
 * otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Subscribe to see which companies asked this question.
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty())
      return -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (nums[middle] == target)
        return middle;
      if (nums[middle] >= nums[low]) {
        if (target >= nums[low] && target < nums[middle])
          high = middle - 1;
        else
          low = middle + 1;
      } else {
        if (target > nums[middle] && target <= nums[high])
          low = middle + 1;
        else
          high = middle - 1;
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> vec{4,5,6,1,2};
  std::cout << test.search(vec, 1) << std::endl;
  return 0;
}