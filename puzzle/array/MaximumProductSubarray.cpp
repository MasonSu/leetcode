// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

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

/* 两个数组，分别记录以第i个节点为结尾的最大和最小值，不用管正负，可能的取值只有那三个 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> vecMax(nums.size()), vecMin(nums.size());
        vecMax[0] = vecMin[0] = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            vecMax[i] = std::max({vecMax[i - 1] * nums[i], vecMin[i - 1] * nums[i], nums[i]});
            vecMin[i] = std::min({vecMax[i - 1] * nums[i], vecMin[i - 1] * nums[i], nums[i]});
            max = std::max(vecMax[i], max);
        }
        return max;
    }
};

class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int num1 = nums[0], num2 = nums[0], localMax = nums[0] , localMin = nums[0], Max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            num1 = localMax * nums[i];
            num2 = localMin * nums[i];
            localMax = std::max({num1, num2, nums[i]});
            localMin = std::min({num1, num2, nums[i]});
            Max = std::max(localMax, Max);
        }
        return Max;
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
