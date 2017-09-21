/**
 * Given an array nums, there is a sliding window of
 * k k which is moving from the very left of the
 * array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window
 * moves right by one position.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 *
 * Note:
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's k for non-empty array.
 *
 * Follow up:
 * Could you solve it in linear time?
 */

#include <vector>
#include <set>
#include <deque>

using std::vector;
using std::multiset;
using std::deque;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty())
      return {};

    multiset<int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      if (i < k) {
        hash.insert(nums[i]);
      } else {
        result.push_back(*(--hash.end()));
        int count = hash.erase(nums[i - k]);
        if (count > 1) {
          while (--count)
            hash.insert(nums[i - k]);
        }
        hash.insert(nums[i]);
      }
    }
    result.push_back(*(--hash.end()));
    return result;
  }
};

class Solution2 {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty())
      return{};

    deque<int> index;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      while (index.size() && nums[i] > nums[index.back()])
        index.pop_back();

      index.push_back(i);

      if (i - index.front() >= k)
        index.pop_front();

      if (i >= k - 1)
        result.push_back(nums[index.front()]);
    }

    return result;
  }
};

int main() {
  vector<int> vec{2, 3, 4, 2, 6, 2, 5, 1};
  Solution2 test;
  vector<int> result = test.maxSlidingWindow(vec, 3);
  return 0;
}