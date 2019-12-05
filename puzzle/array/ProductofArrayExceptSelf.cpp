// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())
            return {};
        int length = nums.size();
        vector<int> result(length), leftProduct(length), rightProduct(length);
        leftProduct[0] = nums[0], rightProduct[length - 1] = nums[length - 1];
        for (int i = 1; i < length; ++i) {
            leftProduct[i] = leftProduct[i - 1] * nums[i];
            rightProduct[length - 1 - i] = rightProduct[length - i] * nums[length - 1 - i];
        }
        result[0] = rightProduct[1];
        for (int i = 1; i < length - 1; ++i)
            result[i] = leftProduct[i - 1] * rightProduct[i + 1];
        result[length - 1] = leftProduct[length - 2];
        return result;
    }
};

/* 只用一个数组 */
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<int> result(nums.size());
        result[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
            result[i] = result[i - 1] * nums[i - 1];
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    vector<int> v1{1,2,3,4,5};
    REQUIRE(test.productExceptSelf(v1) == vector<int>{120,60,40,30,24});
}
