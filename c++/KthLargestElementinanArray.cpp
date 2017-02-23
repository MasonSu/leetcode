/**
 *
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, 
 * not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  int sort(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int index = low;
    for (int i = low; i < high; ++i) {
      if (nums[i] < pivot) {
        std::swap(nums[index], nums[i]);
        index++;
      }
    }
    std::swap(nums[index], nums[high]);
    return index;
  }

  void quicksort(vector<int>& nums, int low, int high) {
    if (low >= high)
      return;
    int middle = sort(nums, low, high);
    quicksort(nums, low, middle - 1);
    quicksort(nums, middle + 1, high);
  }

  int findKthLargest(vector<int>& nums, int k) {
    quicksort(nums, 0, nums.size() - 1);
    return nums[nums.size() - k];
  }
};