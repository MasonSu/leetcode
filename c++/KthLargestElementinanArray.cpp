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
#include <set>
#include <iostream>

using std::vector;
using std::multiset;

/*class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    multiset<int> number(nums.begin(), nums.begin() + k);

    for (int i = k; i < nums.size(); ++i) {
      if (nums[i] > *number.begin()) {
        number.erase(number.begin());
        number.insert(nums[i]);
      }
    }
    return *number.begin();
  }
};*/

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int low = 0, high = nums.size() - 1;
    int index = partition(nums, low, high);
    while (index != nums.size() - k) {
      if (index > nums.size() - k) {
        high = index - 1;
        index = partition(nums, low, high);
      } else {
        low = index + 1;
        index = partition(nums, low, high);
      }
    }
    return nums[index];
  }

private:
  int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high], index = low;
    for (int i = low; i < high; ++i) {
      if (nums[i] < pivot) {
        std::swap(nums[i], nums[index]);
        index++;
      }
    }
    /* Not std::swap(pivot, nums[index]) */
    std::swap(nums[high], nums[index]);
    return index;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> vec{3,2,1,5,6,4};
  std::cout << test.findKthLargest(vec, 2) << '\n';
  return 0;
}