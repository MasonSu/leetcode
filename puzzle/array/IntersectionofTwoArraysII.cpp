// Given two arrays, write a function to compute their intersection.

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:

// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return {};
        unordered_map<int, int> um;
        for (int num : nums1)
            um[num]++;
        vector<int> result;
        for (int num : nums2) {
            if (um[num]-- > 0)
                result.push_back(num);
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return {};
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> result;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};