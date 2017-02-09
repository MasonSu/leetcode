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
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (nums[middle] < target)
        low = middle + 1;
      else if (nums[middle] > target)
        high = middle - 1;
      else
        return middle;
    }
    return -1;
  }

  int search(vector<int>& nums, int target) {
    if (nums.size() == 0)
      return -1;

    vector<int>::iterator maxNumber = std::max_element(nums.begin(), nums.end());
    vector<int> left(nums.begin(), maxNumber + 1);  /* right bound is maxNumber+1, not maxNumber*/
    vector<int> right(maxNumber + 1, nums.end());

    int index = searchInsert(left, target);
    if (index == -1) {
      index = searchInsert(right, target);
      if (index != -1)
        return maxNumber - nums.begin() + index + 1;
    }

    return index;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> vec{4,5,6,1,2};
  std::cout << test.search(vec, 1) << std::endl;
  return 0;
}