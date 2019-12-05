// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Note: The length of the given binary array will not exceed 50,000.

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            if (nums[i] == 0)
                nums[i] = -1;
        }
        int sum = 0, result = 0;
        /* hashTable中存放累加和以及对应的下标
         * 初始值和为0的下标为-1，当遇到和一样的
         * 时候，表明两者之间的和为0，这就是含有
         * 相同数目的0和1
         */
        unordered_map<int, int> table;
        table.insert({0, -1});
        for (int i = 0; i < length; ++i) {
            sum += nums[i];
            if (table.find(sum) != table.end()) {
                if (i - table[sum] > result)
                    result = i - table[sum];
            } else {
                table.insert({sum, i});
            }
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{0,1,0,1,1,1,0,0};
    REQUIRE(test.findMaxLength(v1) == 8);
}
