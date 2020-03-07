// Given an array nums of n integers where n > 1,  return an array 
// output such that output[i] is equal to the product of all the 
// elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output 
// array does not count as extra space for the purpose of space 
// complexity analysis.)

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())
            return {};
        int length = nums.size();
        vector<int> result(length, 1);
        int num = 1;
        for (int i = 1; i < length; ++i) {
            num *= nums[i - 1];
            result[i] *= num;
        }
        num = 1;
        for (int i = length - 2; i >= 0; --i) {
            num *= nums[i + 1];
            result[i] *= num;
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    vector<int> v1{1,2,3,4,5};
    REQUIRE(test.productExceptSelf(v1) == vector<int>{120,60,40,30,24});
}