// Given an array of n positive integers and a positive integer s, find the minimal 
// length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// Example: 

// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int start = 0, end = 0, sum = 0, result_length = INT_MAX;
        while (end < nums.size()) {
        	sum += nums[end];
        	while (sum >= s) {
        		result_length = std::min(result_length, end - start + 1);
        		sum -= nums[start++];
        	}
        	end++;
        }
        return result_length == INT_MAX ? 0 : result_length;
    }
};