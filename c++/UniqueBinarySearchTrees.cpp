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
    if (n == 1 || n == 2)
      return n;
    int arr[n + 1] = {0};
    arr[0] = 1, arr[1] = 1, arr[2] = 2;
    for (int i = 3; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        arr[i] += arr[i - j - 1] * arr[j];
    return arr[n];
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.numTrees(5) << '\n';
  return 0;
}