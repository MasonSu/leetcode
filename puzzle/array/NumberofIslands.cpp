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