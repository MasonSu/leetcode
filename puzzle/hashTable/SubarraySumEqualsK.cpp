// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> table;
        table.insert({0, 1});
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (table.find(sum - k) != table.end())
                count += table[sum - k];
            table[sum]++;
        }
        return count;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{1,1,1};
    REQUIRE(test.subarraySum(v1, 2) == 2);
    v1 = {0,0,0,0,0,0,0,0,0,0};
    REQUIRE(test.subarraySum(v1, 0) == 55);
}
