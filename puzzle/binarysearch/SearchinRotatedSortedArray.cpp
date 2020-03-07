// Suppose an array sorted in ascending order is rotated at 
// some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the 
// array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// 先找到最小值对应的下标，然后转换为简单的二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int start = 0, end = nums.size(), length = end;
        if (nums[0] > nums[length - 1]) {  
            int minIndex = findMin(nums);
            if (target > nums[length - 1]) {
                end = minIndex - 1;
            } else {
                start = minIndex;
            }
        }
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[middle] < target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        if (end < length && nums[end] == target)
            return end;
        return -1;
    }

private:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size(), length = end;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[middle] > nums[length - 1]) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return end;
    }
};