// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
// Example 2:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        return std::max(robmoney(nums, 1, nums.size() - 1), 
                        nums[0] + robmoney(nums, 2, nums.size() - 2));
    }

private:
    int robmoney(vector<int>& nums, int start, int end) {
        if (start > end)
            return 0;
        int length = end - start + 1;
        vector<int> vec(length + 1);
        vec[1] = nums[start];
        // 注意这里nums的下标
        for (int i = 2; i <= length; ++i) {
            vec[i] = std::max(vec[i - 1], nums[++start] + vec[i - 2]);
        }
        assert(start == end);
        return vec[length];
    }
};