/**
 *
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 */

#include <vector>
#include <iostream>

using std::vector;

// class Solution {
// public:
//   int searchInsert(vector<int>& nums, int target) {
//     int low = 0, high = nums.size() - 1;
//     if (target < nums[0])
//       return 0;
//     if (target > nums[high])
//       return high + 1;
//     while (low <= high) {
//       int middle = (low + high) / 2;
//       if (middle == low && nums[middle] != target)
//         break;
//       if (nums[middle] < target)
//         low = middle;
//       else if (nums[middle] > target)
//         high = middle;
//       else
//         return middle;
//     }
//     return low + 1;
//   } 
// };

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
    return low;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> vec = {1, 3, 5, 6};
  std::cout << test.searchInsert(vec, 0) << '\n';
  return 0;
}