/**
 * Given a 2d grid map of '1's (land) and '0's (water),
 * count the number of islands. An island is surrounded
 * by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four
 * edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Answer: 1
 *
 * Example 2:
 *
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Answer: 3
 */

#include <vector>

using std::vector;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
      return 0;

    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> visted(row, vector<int>(col));
    int count = 0;

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (visted[i][j] == 1)
          continue;

        if (grid[i][j] == '1') {
          count++;
          find(grid, visted, i, j);
        }
      }
    }

    return count;
  }

private:
  void find(vector<vector<char>>& grid, vector<vector<int>>& visted, int row, int col) {
    if (visted[row][col] == 1)
      return;

    visted[row][col] = 1;

    if (row - 1 >= 0 && grid[row - 1][col] == '1')
      find(grid, visted, row - 1, col);

    if (row + 1 < grid.size() && grid[row + 1][col] == '1')
      find(grid, visted, row + 1, col);

    if (col - 1 >= 0 && grid[row][col - 1] == '1')
      find(grid, visted, row, col - 1);

    if (col + 1 < grid[row].size() && grid[row][col + 1] == '1')
      find(grid, visted, row, col + 1);
  }
};