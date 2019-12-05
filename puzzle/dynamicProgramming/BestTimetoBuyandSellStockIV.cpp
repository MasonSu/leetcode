// Say you have an array for which the i-th element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Example 1:

// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0)
            return 0;
        int length = prices.size();
        /* 股票最多可以交易length/2次，也就是第一天买，第二天卖，如此重复。当k大于
         * 等于这个值时，问题就退化为了不限k的解法，不加这个的话，有的测试用例会提示
         * std::bad_alloc异常
         */
        if (k >= length / 2) {
            int result = 0;
            for (int i = 1; i < length; ++i) {
                if (prices[i] > prices[i - 1])
                    result += prices[i] - prices[i - 1];
            }
            return result;
        }
        /* vec[i][j]代表最多进行i次交易，到第j天时所能获得的最大利润
         * vec[i][j] = std::max(vec[i][j - 1], std::max(prices[j] - prices[m] + vec[i - 1][m - 1]))
         * 其中0 <= m < j，当m等于0时，vec[i - 1][m - 1]无意义，应该取为0，上面那个表达式的第二项可以被改写为
         * prices[j] + std::max(vec[i - 1][m - 1] - prices[m])，这样后面那个max可以在循环过程中更新，
         * 而不需要从前往后再遍历一遍，可以将时间复杂度从O(k*N^2)降为O(K*N)
         */
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

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<int> v1{2,5,7,1,4,3,1,3};
    REQUIRE(test.maxProfit(3, v1) == 10);
}
