// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

// You need to find the shortest such subarray and output its length.

// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Note:
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.

/* 需要排序的最短子数组长度 */
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int first = 0, second = nums.size() - 1;
        while (first < second) {
            if (nums[first] > nums[first + 1])
                break;
            first++;
        }
        if (first == second)
            return 0;
        while (second > first) {
            if (nums[second] < nums[second - 1])
                break;
            second--;
        }
        /* 上面那个是最初的答案，没有考虑到区间中间有更小或更大的值 */
        int min = nums[first], max = nums[second];
        for (int i = first; i <= second; ++i) {
            if (nums[i] < min)
                min = nums[i];
            if (nums[i] > max)
                max = nums[i];
        }

        first--;
        while (first >= 0 && min < nums[first]) {
            first--;
        }

        second++;
        while (second <= nums.size() - 1 && max > nums[second])
            second++;

        return second - first - 1;
    }
};

class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int length = nums.size(), max = nums[0], min = nums[length - 1], end = 0, start = length - 1;
        for (int i = 1; i < length; ++i) {
            if (nums[i] < max) {
                end = i;
            } else {
                max = nums[i];
            }

            if (nums[length - 1 - i] > min) {
                start = length - 1 - i;
            } else {
                min = nums[length - 1 - i];
            }
        }
        if (end == 0 || start == length - 1)
            return 0;
        return end - start + 1;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    vector<int> v1{1,5,3,4,2,6,7};
    REQUIRE(test.findUnsortedSubarray(v1) == 4);
    vector<int> v2{2,6,4,8,10,9,15};
    REQUIRE(test.findUnsortedSubarray(v2) == 5);
    vector<int> v3{1,2,3,4,5};
    REQUIRE(test.findUnsortedSubarray(v3) == 0);
    vector<int> v4{5,4,3,2,1};
    REQUIRE(test.findUnsortedSubarray(v4) == 5);
    vector<int> v5{1,5,4,2,3};
    REQUIRE(test.findUnsortedSubarray(v5) == 4);
    vector<int> v6{1,3,2,2,2};
    REQUIRE(test.findUnsortedSubarray(v6) == 4);
}
