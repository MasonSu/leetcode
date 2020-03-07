// Given an array of integers, return indices of the two numbers 
// such that they add up to a specific target.

// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

// 这里需要返回数据对应的下标
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> c;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (c.find(target - nums[i]) != c.end()) {
                    result.push_back(i);
                    result.push_back(c[target - nums[i]]);
                    break;   
            }
            c.insert({nums[i], i});
        }
        return result;
    }
};