// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times
// k transactions at day i
// vec[k][i] = max(vec[k][i - 1], prices[i] - prices[j] + vec[k - 1][j]) 0 <= j < i
//           = max(vec[k][i - 1], prices[i] + vec[k - 1][j] - prices[j]) 0 <= j < i
//           = max(vec[k][i - 1], prices[i] + max(vec[k - 1][j] - prices[j])) 0 <= j < i

// O(k * N^2)
class Solution {
public:
    int maxProfit(vector<int> prices) {
        if (prices.size() < 2)
            return 0;
        int length = prices.size(), k = 2;
        // 这里是length，不是length + 1
        vector<vector<int>> vec(k + 1, vector<int>(length));
        for (int i = 1; i <= k; ++i) {
            int max_diff = INT_MIN;
            for (int j = 1; j < length; ++j) {
                for (int m = 0; m < j; ++m) {
                    max_diff = std::max(max_diff, vec[i - 1][m] - prices[m]);
                }
                vec[i][j] = std::max(vec[i][j - 1], prices[j] + max_diff);
            }
        }
        return vec[k][length - 1];
    }
};

// O(k * N)
class Solution2 {
public:
    int maxProfit(vector<int> prices) {
        if (prices.size() < 2)
            return 0;
        int length = prices.size(), k = 2;
        // 这里是length，不是length + 1
        vector<vector<int>> vec(k + 1, vector<int>(length));
        for (int i = 1; i <= k; ++i) {
            int max_diff = INT_MIN;
            for (int j = 1; j < length; ++j) {
                max_diff = std::max(max_diff, vec[i - 1][j - 1] - prices[j - 1]);
                vec[i][j] = std::max(vec[i][j - 1], prices[j] + max_diff);
            }
        }
        return vec[k][length - 1];
    }
};