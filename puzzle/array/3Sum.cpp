// Given an array nums of n integers, are there elements a, b, c 
// in nums such that a + b + c = 0? Find all unique triplets in 
// the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 这里有个难点是如何去除重复的结果，如果使用hashmap不能
// 很好的解决这个问题
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;
            int start = i + 1, end = nums.size() - 1;
            int target = -nums[i];
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == target) {
                    result.push_back({nums[i], nums[start++], nums[end--]});
                    while (start < end && nums[start] == nums[start - 1])
                        start++;
                    while (start < end && nums[end] == nums[end + 1])
                        end--;
                } else if (sum > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return result;
    }
};