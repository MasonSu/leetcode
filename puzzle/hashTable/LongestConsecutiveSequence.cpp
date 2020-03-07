// Given an unsorted array of integers, find the length of 
// the longest consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is 
// [1, 2, 3, 4]. Therefore its length is 4.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> us;
        for (auto i : nums)
            us.insert(i);
        int result = 1;
        for (int i = 0; i < nums.size(); ++i) {
        	// nums[i]为连续序列的第一个数，每个数只能进入到这个内部循环1次
            if (us.find(nums[i] - 1) == us.end()) {
                int j = nums[i];
                while (us.find(j) != us.end())
                    j++;
                result = std::max(result, j - nums[i]);
            }
        }
        return result;
    }
};