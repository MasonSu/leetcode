/* Unbounded Knapsack */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        if (coins.empty())
            return 0;
        int lengthX = coins.size(), lengthY = amount;
        vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
        for (int i = 0; i <= lengthX; ++i)
            vec[i][0] = 1;
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                if (coins[i - 1] <= j)
                    vec[i][j] = vec[i - 1][j] + vec[i][j - coins[i - 1]];
                else
                    vec[i][j] = vec[i - 1][j];
            }
        }
        return vec[lengthX][lengthY];
    }
};