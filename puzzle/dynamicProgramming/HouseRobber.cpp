class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int length = nums.size();
        vector<int> vec(length + 1, 0);
        vec[1] = nums[0];
        for (int i = 2; i <= length; ++i)
            vec[i] = std::max(nums[i - 1] + vec[i - 2], vec[i - 1]);
        return vec[length];
    }
};

/* 空间复杂度为O(1)，result初始值为nums[0]，防止只有一个元素 */
class Solution2 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int first = 0, second = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result = std::max(nums[i] + first, second);
            first = second;
            second = result;
        }
        return result;
    }
};