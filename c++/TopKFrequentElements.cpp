/**
 * Given a non-empty array of integers, return the k
 * most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note:
 * You may assume k is always valid, 1 ? k ? number of
 * unique elements.
 * Your algorithm's time complexity must be better than
 * O(n log n), where n is the array's size.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::priority_queue;

// Time:  O(nlogk)
// Space: O(n)
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for (int i : nums)
      hash[i]++;

    /* 默认是最大堆，如果是pair，默认会对first排序 */
    priority_queue<std::pair<int, int>> heap;
    for (auto iter = hash.begin(); iter != hash.end(); ++iter) {
      heap.push({ -iter->second, iter->first});
      if (heap.size() > k)
        heap.pop();
    }

    vector<int> result;
    while (!heap.empty()) {
      result.push_back(heap.top().second);
      heap.pop();
    }

    return result;
  }
};