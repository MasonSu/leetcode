/**
 * You are given coins of different denominations and
 * a total amount of money amount. Write a function
 * to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money
 * cannot be made up by any combination of the coins,
 * return -1.
 *
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

/* Failed */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0)
      return 0;
    vector<int> vec(amount + 1, INT_MAX);
    vec[0] = 0;
    for (int i = 1; i < amount + 1; ++i) {
      for (int j = 0; j < coins.size(); ++j) {
        if (coins[j] <= i && vec[i - coins[j]] != INT_MAX)
          vec[i] = std::min(vec[i], vec[i - coins[j]] + 1);
      }
    }
    return vec[amount] == INT_MAX ? -1 : vec[amount];
  }
};