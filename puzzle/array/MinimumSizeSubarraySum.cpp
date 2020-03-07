// Given an array of n positive integers and a positive integer s, 
// find the minimal length of a contiguous subarray of which the 
// sum ≥ s. If there isn't one, return 0 instead.

// Example: 

// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.

/* 给定一个正整数数组和正整数s,返回和大于等于s的连续子数组的最小长度 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int start = 0, sum = 0, result = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                result = std::min(result, i - start + 1);
                sum -= nums[start++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};