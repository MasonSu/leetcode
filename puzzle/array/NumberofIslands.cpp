// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
      return 0;

    vector<vector<int>> visted(grid.size(), vector<int>(grid[0].size()));
    int count = 0;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == '1' && !visted[i][j]) {
          count++;
          dfs(grid, visted, i, j);
        }
      }
    }

    return count;
  }

private:
  void dfs(vector<vector<char>>& grid, vector<vector<int>>& visted, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size())
      return;

    if (grid[row][col] == '0' || visted[row][col])
      return;

    visted[row][col] = 1;

    dfs(grid, visted, row - 1, col);
    dfs(grid, visted, row + 1, col);
    dfs(grid, visted, row, col - 1);
    dfs(grid, visted, row, col + 1);
  }
};