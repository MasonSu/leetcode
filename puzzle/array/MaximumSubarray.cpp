class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int max = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum = sum > 0 ? sum + nums[i] : nums[i];
            max = sum > max ? sum : max;
        }
        return max;
    }
};