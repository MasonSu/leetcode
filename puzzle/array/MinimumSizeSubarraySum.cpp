// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// Example: 

// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
// Follow up:
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

/* 给定一个正整数数组和正整数s,返回和大于等于s的连续子数组的最小长度 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s == 0 || nums.empty())
            return 0;
        int first = 0, second = 0, sum = nums[0], length = INT_MAX;
        while (first <= second) {
            if (sum < s) {
                second++;
                if (second == nums.size())
                    break;
                sum += nums[second];
            } else if (sum >= s) {
                length = std::min(length, second - first + 1);
                sum -= nums[first++];
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};