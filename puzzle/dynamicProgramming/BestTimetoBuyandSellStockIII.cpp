class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int length = prices.size(), k = 2;
        vector<vector<int>> vec(k + 1, vector<int>(length));
        for (int i = 1; i <= k; ++i) {
            int localMax = -prices[0];
            for (int j = 1; j < length; ++j) {
                vec[i][j] = std::max(vec[i][j - 1], prices[j] + localMax);
                localMax = std::max(localMax, vec[i - 1][j - 1] - prices[j]);
            }
        }
        return vec[k][length - 1];
    }
};