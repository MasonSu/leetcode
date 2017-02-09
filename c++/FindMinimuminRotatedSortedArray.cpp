/**
 *
 * Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 *
 */

/* Failed */
#include <vector>

using std::vector;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      if (nums[low] < nums[high])
        return nums[low];
      int middle = low + (high - low) / 2;
      if (nums[middle] >= nums[low])
        low = middle + 1;
      else
        high = middle;
    }
    return nums[low];
  }
};

int main(int argc, char const *argv[])
{

  return 0;
}