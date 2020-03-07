// Given an array of integers nums sorted in ascending order, find the 
// starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1,-1};
        // 这里很巧妙，采用target + 1来寻找last num的下一个位置
        int start = binarySearch(nums, target), last = binarySearch(nums, target + 1);
        if (start >= nums.size() || nums[start] != target)
            start = -1;
        last--;
        if (last >= nums.size() || nums[last] != target)
            last = -1;
        return {start, last};
    }
    
private:
    int binarySearch(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (target > nums[middle]) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return end;
    }
};