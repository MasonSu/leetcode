// Given a sorted array nums, remove the duplicates in-place such that 
// duplicates appeared at most twice and return the new length.

// Do not allocate extra space for another array, you must do this by 
// modifying the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements 
// of nums being 1, 1, 2, 2 and 3 respectively.

// It doesn't matter what you leave beyond the returned length.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int result = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[result - 2])
                nums[result++] = nums[i];
        }
        return result;
    }
};

// at most k duplicates
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums, int k) {
        if (nums.size() <= k)
            return nums.size();
        int result = k;
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] != nums[result - k])
                nums[result++] = nums[i];
        }
        return result;
    }
};