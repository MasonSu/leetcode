// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

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

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty())
            return false;
        vector<int> vec;
        vec.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
           auto iter = std::lower_bound(vec.begin(), vec.end(), nums[i]);
           if (iter == vec.end()) {
               vec.push_back(nums[i]);
               if (vec.size() == 3) 
                   return true;	
           } else {
               *iter = nums[i];
           }
        }
        return false;
    }
};

class Solution2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty())
            return false;
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
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