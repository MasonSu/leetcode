/**
 * Given a positive integer n, find the least number of perfect
 * square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4;
 * given n = 13, return 2 because 13 = 4 + 9.
 */

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using std::vector;

class Solution {
public:
  int numSquares(int n) {
    vector<int> vec(n + 1, INT_MAX);
    vec[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        vec[i] = std::min(vec[i], vec[i - j * j] + 1);
      }
    }
    return vec[n];
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.numSquares(8) << '\n';
  return 0;
}