/**
 *
 * Given an array with n objects colored red, white or blue, 
 * sort them so that objects of the same color are adjacent, 
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the 
 * color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;

/*class Solution {
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

  void quickSort(vector<int>& nums, int low, int high) {
    if (low >= high)
      return;
    int middle = sort(nums, low, high);
    quickSort(nums, low, middle - 1);
    quickSort(nums, middle + 1, high);
  }

  void sortColors(vector<int>& nums) {
    if (nums.empty())
      return;
    quickSort(nums, 0, nums.size() - 1);
  }
};*/

class Solution {
public:
  void sortColors(vector<int>& nums) {
    if (nums.empty())
      return;
    int zero = 0, second = nums.size() - 1;
    for (int i = 0; i <= second; ++i) {
      if (nums[i] == 0) {
        std::swap(nums[zero], nums[i]);
        zero++;
      } else if (nums[i] == 2) {
        std::swap(nums[i], nums[second]);
        second--;
        i--;
      } 
    }
  }
};