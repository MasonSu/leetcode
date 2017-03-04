/**
 *
 * Given n, how many structurally unique BST's (binary search trees)
 * that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 */

/* Failed */
#include <iostream>
#include <algorithm>

class Solution {
public:
  int numTrees(int n) {
    if (n <= 1)
      return 1;
    int D[n+1];
    std::fill_n(D, n+1, 0);
    D[0] = 1, D[1] = 1;
    for (int i = 2; i < n + 1; ++i)
      for (int j = 0; j < i; ++j)
        D[i] += D[j] * D[i - 1 - j];
    return D[n];
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.numTrees(5) << '\n';
  return 0;
}