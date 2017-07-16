/**
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids.
 * How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively
 * in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 */

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty())
      return 0;

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    /* https://stackoverflow.com/questions/3082914/
       c-compile-error-variable-sized-object-may-not-be-initialized*/
    // long long arr[m][n] = {0};
    vector<vector<int>> arr(m, std::vector<int>(n, 0));

    if (obstacleGrid[0][0] == 1)
      return 0;

    arr[0][0] = 1;

    for (int i = 1; i < m; ++i) {
      if (obstacleGrid[i][0] == 1)
        break;
      arr[i][0] = 1;
    }

    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[0][j] == 1)
        break;
      arr[0][j] = 1;
    }

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (obstacleGrid[i][j] == 0)
          arr[i][j] = arr[i - 1][j] + arr[i][j - 1];

    return arr[m - 1][n - 1];
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  /* https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector */
  vector<vector<int>> vec{{0, 1}, {0, 0}};
  std::cout << test.uniquePathsWithObstacles(vec) << '\n';
  return 0;
}