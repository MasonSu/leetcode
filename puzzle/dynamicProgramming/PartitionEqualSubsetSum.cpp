/* 0-1 Knapsack */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return false;
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum & 1)
            return false;
        int target = sum / 2;
        int lengthX = nums.size(), lengthY = target;
        vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
        /* 当target为0时，将这一列全都置为1 */
        for (int i = 0; i <= lengthX; ++i)
            vec[i][0] = 1;
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                if (nums[i - 1] <= j)
                    vec[i][j] = vec[i - 1][j] || vec[i - 1][j - nums[i - 1]];
                else
                    vec[i][j] = vec[i - 1][j];
            }
        }
        return vec[lengthX][lengthY] == 1;
    }
};