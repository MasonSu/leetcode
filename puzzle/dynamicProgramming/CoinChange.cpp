class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
            return -1;
        std::sort(coins.begin(), coins.end());
        vector<int> vec(amount + 1, INT_MAX);
        vec[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size() && coins[j] <= i; ++j) {
                if (vec[i - coins[j]] != INT_MAX) {
                    vec[i] = std::min(vec[i], vec[i - coins[j]] + 1);
                }
            }
        }
        return vec[amount] == INT_MAX ? -1 : vec[amount];
    }
};