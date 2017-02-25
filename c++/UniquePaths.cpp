/**
 *
 * A robot is located at the top-left corner of a m x n
 * grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 */

class Solution {
public:
  int uniquePaths(int m, int n) {
    int arr[m][n];
    arr[0][0] = 1;
    for (int i = 1; i < m; ++i)
      arr[i][0] = 1;
    for (int j = 1; j < n; ++j)
      arr[0][j] = 1;
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        arr[i][j] = arr[i - 1][j] + arr[i][j - 1];

    return arr[m - 1][n - 1];
  }
};