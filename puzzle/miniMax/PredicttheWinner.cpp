class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.empty())
            return true;
        vector<vector<int>> vec(nums.size(), vector<int>(nums.size(), -1));
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int sum = dfs(vec, nums, 0, nums.size() - 1);
        return sum * 2 >= totalSum;
    }
private:
    int dfs(vector<vector<int>>& vec, vector<int>& nums, int begin, int end) {
        if (begin > end)
            return 0;
        if (begin == end)
            vec[begin][end] = nums[begin];
        if (vec[begin][end] == -1) {
            int num1 = nums[begin] + std::min(dfs(vec, nums, begin + 2, end), dfs(vec, nums, begin + 1, end - 1));
            int num2 = nums[end] + std::min(dfs(vec, nums, begin + 1, end - 1), dfs(vec, nums, begin, end - 2));
            vec[begin][end] = std::max(num1, num2);
        }
        return vec[begin][end];
    }
};