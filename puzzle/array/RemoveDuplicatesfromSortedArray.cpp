// Given a sorted array nums, remove the duplicates in-place 
// such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by 
// modifying the input array in-place with O(1) extra memory.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[result - 1])
                nums[result++] = nums[i];
        }
        return result;
    }
};