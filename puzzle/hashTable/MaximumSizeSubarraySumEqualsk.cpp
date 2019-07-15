class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> table;
        table.insert({0, -1});
        int sum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (table.find(sum - k) != table.end()) {
                if (i - table[sum - k] > result)
                    result = i - table[sum - k];
            }
            if (table.find(sum) == table.end())
                table.insert({sum, i});
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