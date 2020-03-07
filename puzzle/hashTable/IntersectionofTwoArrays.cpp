// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Note:

// Each element in the result must be unique.
// The result can be in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us;
        for (int num : nums1)
            us.insert(num);
        vector<int> result;
        for (int i = 0; i < nums2.size() && us.size(); ++i) {
            if (us.count(nums2[i]) != 0) {
                result.push_back(nums2[i]);
                us.erase(nums2[i]);
            }
        }
        return result;
    }
};