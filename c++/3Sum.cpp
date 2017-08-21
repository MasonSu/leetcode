/**
 * Given an array S of n integers, are there elements a, b, c
 * in S such that a + b + c = 0? Find all unique triplets in
 * the array which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); ++i) {
      if (i >= 1 && nums[i] == nums[i - 1])
        continue;

      int target = -nums[i];
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
        int sum = nums[j] + nums[k];
        if (sum < target)
          j++;
        else if (sum > target)
          k--;
        else {
          result.push_back(vector<int> {nums[i], nums[j], nums[k]});
          j++;
          k--;

          while (nums[j] == nums[j - 1])
            j++;
          while (nums[k] == nums[k + 1])
            k--;
        }
      }
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> vec{ -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  Solution test;
  test.threeSum(vec);

  return 0;
}