class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int first = 0, second = 0, last = 0, count = 0;
        while (last < nums.size() - 1) {
            for (int i = first; i <= second; ++i)
                last = std::max(last, i + nums[i]);
            count++;
            first = second++;
            second = last;
        }
        return count;
    }
};