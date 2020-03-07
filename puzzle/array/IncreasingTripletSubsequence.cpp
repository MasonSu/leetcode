// Given an unsorted array return whether an increasing subsequence of length 3 
// exists or not in the array.

// Formally the function should:

// Return true if there exists i, j, k
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Example 1:

// Input: [1,2,3,4,5]
// Output: true
// Example 2:

// Input: [5,4,3,2,1]
// Output: false

// first和second在循环过程中取尽可能小的数，这样才会更容易满足条件
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty())
            return false;
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            // 这里的两个条件都必须用小于等于，否则3个相同的数也会返回true
            if (nums[i] <= first) {
                first = nums[i];
            } else if (nums[i] <= second) {
                second = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};