// Given an array, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Note:

// Try to come up as many solutions as you can, there are at least 3 different ways to 
// solve this problem.
// Could you do it in-place with O(1) extra space?

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty())
            return;
        int length = nums.size();
        reverse(nums, 0, length - 1);
        k = k % length;
        reverse(nums, 0, k - 1);
        reverse(nums, k, length - 1);
    }
    
private:
    void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            std::swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }
};