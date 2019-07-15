class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty())
      return 0;

    int max = 0;
    vector<vector<int>> visted(grid.size(), vector<int>(grid[0].size()));

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (!grid[i][j] || visted[i][j])
          continue;

        int count = 0;
        dfs(grid, visted, count, i, j);
        if (count > max)
          max = count;
      }
    }

    return max;
  }

private:
  void dfs(vector<vector<int>>& grid, vector<vector<int>>& visted, int& count, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size())
      return;

    if (visted[row][col] || !grid[row][col])
      return;

    visted[row][col] = 1;
    count++;

    dfs(grid, visted, count, row - 1, col);
    dfs(grid, visted, count, row + 1, col);
    dfs(grid, visted, count, row, col - 1);
    dfs(grid, visted, count, row, col + 1);
  }
};