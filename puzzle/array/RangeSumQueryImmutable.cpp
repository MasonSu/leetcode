// Given an integer array nums, find the sum of the elements 
// between indices i and j (i ≤ j), inclusive.

// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0, length = nums.size();
        prefix_sum.resize(length + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            prefix_sum[i + 1] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return prefix_sum[j + 1] - prefix_sum[i];
    }
    
private:
    vector<int> prefix_sum;
};