/**
* Given an unsorted array of integers, find the
* length of longest increasing subsequence.
*
* For example,
* Given [10, 9, 2, 5, 3, 7, 101, 18],
* The longest increasing subsequence is [2, 3, 7, 101],
* therefore the length is 4. Note that there may be more
* than one LIS combination, it is only necessary for you
* to return the length.
*
* Your algorithm should run in O(n2) complexity.
*
* Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution1 {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())
      return 0;

    vector<int> sorted(nums);
    std::sort(sorted.begin(), sorted.end());

    int length = nums.size();
    int arr[length + 1][length + 1];

    for (int i = 0; i <= length; ++i) {
      for (int j = 0; j <= length; ++j) {
        if (i == 0 || j == 0)
          arr[i][j] = 0;
        else if (nums[i - 1] == sorted[j - 1])
          arr[i][j] = arr[i - 1][j - 1] + 1;
        else
          arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
      }
    }

    return arr[length][length];
  }
};

class Solution2 {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())
      return 0;

    vector<int> result(nums.size(), 1);
    int max = 1;

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] > nums[j])
          result[i] = std::max(result[j] + 1, result[i]);

        if (result[i] > max) {
          max = result[i];
          break;
        }
      }
    }

    return max;
  }
};

class Solution3 {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())
      return 0;

    vector<int> result{ nums[0] };
    int index = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > result[index]) {
        result.push_back(nums[i]);
        index++;
      }
      else {
        int pos = binarySearch(result, nums[i]);
        result[pos] = nums[i];
      }
    }

    return index + 1;
  }

private:
  int binarySearch(vector<int>& vec, int target) {
    int low = 0, high = vec.size() - 1;

    while (low <= high) {
      int middle = low + (high - low) / 2;

      if (vec[middle] > target)
        high = middle - 1;
      else if (vec[middle] < target)
        low = middle + 1;
      else
        return middle;
    }

    return low;
  }
};