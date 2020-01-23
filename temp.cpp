#define CATCH_CONFIG_MAIN
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        return std::max(robmoney(nums, 0, nums.size() - 2), robmoney(nums, 1, nums.size() - 1));
    }

private:
    int robmoney(vector<int>& nums, int start, int end) {
        if (start > end)
            return 0;
        int length = end - start + 1;
        vector<int> vec(length + 1);
        vec[1] = nums[start];
        for (int i = 2; i <= length; ++i) {
            vec[i] = std::max(vec[i - 1], nums[++start] + vec[i - 2]);
        }
        assert(start == end);
        return vec[length];
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> vec{6,6,4,8,4,3,3,10};
    REQUIRE(test.rob(vec) == 27);
}