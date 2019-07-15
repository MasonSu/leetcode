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
