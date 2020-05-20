// Given a m x n grid filled with non-negative numbers, find a path from top 
// left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example:
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int lengthX = grid.size(), lengthY = grid[0].size();
        vector<vector<int>> vec(lengthX, vector<int>(lengthY, 0));
        vec[0][0] = grid[0][0];
        for (int i = 1; i < lengthX; ++i)
            vec[i][0] = vec[i - 1][0] + grid[i][0];
        for (int i = 1; i < lengthY; ++i)
            vec[0][i] = vec[0][i - 1] + grid[0][i];
        for (int i = 1; i < lengthX; ++i) {
            for (int j = 1; j < lengthY; ++j) {
                vec[i][j] = std::min(vec[i - 1][j], vec[i][j - 1]) + grid[i][j];
            }
        }
        return vec[lengthX - 1][lengthY - 1];
    }
};

class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int lengthX = grid.size(), lengthY = grid[0].size();
        int more = std::max(lengthX, lengthY), less = std::min(lengthX, lengthY);
        bool rowGreater = more == lengthX;
        vector<int> vec(less);
        vec[0] = grid[0][0];
        for (int i = 1; i < less; ++i)
            vec[i] = vec[i - 1] + (rowGreater ? grid[0][i] : grid[i][0]);
        for (int i = 1; i < more; ++i) {
            for (int j = 0; j < less; ++j) {
                if (j == 0) {
                    vec[j] = vec[j] + (rowGreater ? grid[i][0] : grid[0][i]);
                } else {
                    vec[j] = std::min(vec[j - 1], vec[j]) + (rowGreater ? grid[i][j] : grid[j][i]);
                }
            }
        }
        return vec.back();
    }
};