// Given a set of distinct positive integers, find the largest subset 
// such that every pair (Si, Sj) of elements in this subset satisfies:

// Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

// Example 1:

// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
// Example 2:

// Input: [1,2,4,8]
// Output: [1,2,4,8]

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty())
            return {};
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        // pre_index保存能整除的上一个数的坐标，默认为-1
        vector<int> vec(length, 1), pre_index(length, -1);
        int max = 1, end = 0;
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && vec[j] + 1 > vec[i]) {
                    vec[i] = vec[j] + 1;
                    pre_index[i] = j;
                }
            }
            if (vec[i] > max) {
                max = vec[i];
                end = i;
            }
        }
        vector<int> result;
        while (end != -1) {
            result.push_back(nums[end]);
            end = pre_index[end];
        }
        return result;
    }  
};