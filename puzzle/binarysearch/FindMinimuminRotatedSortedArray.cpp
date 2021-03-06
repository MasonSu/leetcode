// Suppose an array sorted in ascending order is rotated at 
// some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Example 1:

// Input: [3,4,5,1,2] 
// Output: 1
// Example 2:

// Input: [4,5,6,7,0,1,2]
// Output: 0

class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        if (nums[0] <= nums[length - 1])
            return nums[0];
        int start = 0, end = length;
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (nums[middle] > nums[length - 1]) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return nums[end];
    }
};