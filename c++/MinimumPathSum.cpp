/**
 *
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes
 * the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 */

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty())
      return 0;
    int m = grid.size(), n = grid[0].size(), array[m][n] = {0};
    array[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i)
      array[i][0] = array[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; ++j)
      array[0][j] = array[0][j - 1] + grid[0][j];
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        array[i][j] = std::min(array[i - 1][j], array[i][j - 1]) + grid[i][j];
    return array[m - 1][n - 1];
  }
};