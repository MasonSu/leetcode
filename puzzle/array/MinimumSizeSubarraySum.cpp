/* 给定一个正整数数组和正整数s,返回和大于等于s的连续子数组的最小长度 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s == 0 || nums.empty())
            return 0;
        int first = 0, second = 0, sum = nums[0], length = INT_MAX;
        while (first <= second) {
            if (sum < s) {
                second++;
                if (second == nums.size())
                    break;
                sum += nums[second];
            } else if (sum >= s) {
                length = std::min(length, second - first + 1);
                sum -= nums[first++];
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};