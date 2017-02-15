/**
 *
 * Given an array and a value, remove all instances of that value in place
 * and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place
 * with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * Your function should return length = 2, with the first two elements of nums being 2.
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::sort;
using std::cout;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[count++] = nums[i];
      }
    }
    return count;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> nums = {3, 2, 2, 3};
  cout << test.removeElement(nums, 3) << '\n';
  return 0;
}