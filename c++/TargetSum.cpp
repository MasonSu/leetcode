/**
 * You are given a list of non-negative integers, a1, a2, ..., an,
 * and a target, S. Now you have 2 symbols + and -. For each integer,
 * you should choose one from + and - as its new symbol.
 *
 * Find out how many ways to assign symbols to make sum of integers
 * equal to target S.
 *
 * Example 1:
 *
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 *
 * Note:
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    if (nums.empty())
      return 0;

    return findTarget(nums.begin(), nums.end() - 1, S);
  }

private:
  int findTarget(vector<int>::iterator start, vector<int>::iterator end, int target) {
    if (start != end)
      return findTarget(start, end - 1, target - *end) + findTarget(start, end - 1, target + *end);
    else {
      if (*start == target && *start == -target)
        return 2;
      else if (*start == target || *start == -target)
        return 1;
      else
        return 0;
    }
  }
};

class Solution2 {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    if (nums.empty())
      return 0;

    if (nums.size() == 1) {
      if (nums[0] == S && nums[0] == -S)
        return 2;
      else if (nums[0] == S || nums[0] == -S)
        return 1;
      else
        return 0;
    }

    int count = 0;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0) {
        if (nums[i] == 0)
          hash.insert({0, 2});
        else {
          hash.insert({nums[i], 1});
          hash.insert({ -nums[i], 1});
        }
      } else if (i == nums.size() - 1) {
        if (hash.find(S - nums[i]) != hash.end())
          count += hash[S - nums[i]];
        if (hash.find(S + nums[i]) != hash.end())
          count += hash[S + nums[i]];
      } else {
        unordered_map<int, int> tmpHash;
        for (auto iter = hash.begin(); iter != hash.end(); ++iter) {
          int num1 = iter->first - nums[i], num2 = iter->first + nums[i];
          if (tmpHash.find(num1) != tmpHash.end())
            tmpHash[num1] += iter->second;
          else
            tmpHash.insert({num1, iter->second});

          if (tmpHash.find(num2) != tmpHash.end())
            tmpHash[num2] += iter->second;
          else
            tmpHash.insert({num2, iter->second});
        }

        hash.swap(tmpHash);
      }
    }

    return count;
  }
};

/* https://discuss.leetcode.com/topic/76243/
 * java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation
 */
class Solution3 {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0;
    for (auto i : nums)
      sum += i;

    if (sum < S)
      return 0;

    sum += S;

    if (sum % 2)
      return 0;

    int target = sum / 2;
    vector<int> result(target + 1);
    result[0] = 1;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= 0; --j) {
        if (nums[i] <= j)
          if (result[j - nums[i]] != 0)
            result[j] += result[j - nums[i]];
      }
    }

    return result[target];
  }
};