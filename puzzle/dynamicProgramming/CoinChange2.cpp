// You are given coins of different denominations and a total amount of money. 
// Write a function to compute the number of combinations that make up that amount. 
// You may assume that you have infinite number of each kind of coin.

// Example 1:

// Input: amount = 5, coins = [1, 2, 5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10] 
// Output: 1

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

class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        if (coins.empty())
            return 0;
        vector<int> result(amount + 1, 0);
        result[0] = 1;
        std::sort(coins.begin(), coins.end());
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                result[j] += result[j - coins[i]];
            }
        }
        return result[amount];
    }
};