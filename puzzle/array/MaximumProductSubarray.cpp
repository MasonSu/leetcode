// Given an integer array nums, find the contiguous subarray within an array 
// (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

/* 数组中子数组的最大累乘积 */
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int max = nums[0], min = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int num1 = max * nums[i], num2 = min * nums[i];
            max = std::max({num1, num2, nums[i]});
            min = std::min({num1, num2, nums[i]});
            result = std::max(result, max);
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    vector<int> v1{2,3,-2,4};
    REQUIRE(test.maxProduct(v1) == 6);
    vector<int> v2{-2, 4, 0, 3, 5, 8, -1};
    REQUIRE(test.maxProduct(v2) == 120);
    vector<int> v3{2,3,-2,8,1,-3,-4,5};
    REQUIRE(test.maxProduct(v3) == 480);
}
