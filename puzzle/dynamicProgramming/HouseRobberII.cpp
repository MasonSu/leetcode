class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        return std::max(nums[0] + robMax(nums, 2, nums.size() - 2), robMax(nums, 1, nums.size() - 1));
    }
private:
    int robMax(vector<int>& nums, int begin, int end) {
        if (begin > end)
            return 0;
        int first = 0, second = nums[begin], result = nums[begin];
        for (int i = begin + 1; i <= end; ++i) {
            result = std::max(nums[i] + first, second);
            first = second;
            second = result;
        }
        return result;
    }
};