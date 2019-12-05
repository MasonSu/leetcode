// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
// Note:

// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> vec;
        vec.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
           auto iter = std::lower_bound(vec.begin(), vec.end(), nums[i]);
           if (iter == vec.end())
               vec.push_back(nums[i]);
           else
               *iter = nums[i];
        }
        return vec.size();
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{3,5,6,2,5,4,19,5,6,7,12};
    REQUIRE(test.lengthOfLIS(v1) == 6);
}
