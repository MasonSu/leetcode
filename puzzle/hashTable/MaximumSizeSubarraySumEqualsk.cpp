// Given an array arr[] of size n containing integers. The problem 
// is to find the length of the longest sub-array having sum equal 
// to the given value k.

class Solution {
public:
    int maxSubArrayLen(vector<int> nums, int k) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> um;
        um[0] = -1;
        int sum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (um.count(sum - k) != 0)
                result = std::max(result, i - um[sum - k]);
            // 只有不存在时才插入，因为较小的index更可能获得更大的值
            if (um.count(sum) == 0)
                um[sum] = i;
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{1, -1, 5, -2, 3};
    REQUIRE(test.maxSubArrayLen(v1, 3) == 4);
    v1 = {-2, -1, 2, 1};
    REQUIRE(test.maxSubArrayLen(v1, 1) == 2);
}