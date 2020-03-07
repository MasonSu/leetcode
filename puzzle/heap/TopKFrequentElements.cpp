// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n 
// is the array's size.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty())
            return {};
        unordered_map<int, int> um;
        for (int num : nums)
            um[num]++;
        // 最小堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;
        for (auto iter = um.begin(); iter != um.end(); ++iter) {
            q.push({iter->second, iter->first});
            if (q.size() > k)
                q.pop();
        }
        vector<int> result;
        while (q.size()) {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};