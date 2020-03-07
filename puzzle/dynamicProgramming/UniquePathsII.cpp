// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        int lengthX = obstacleGrid.size(), lengthY = obstacleGrid[0].size();
        vector<vector<int>> vec(lengthX, vector<int>(lengthY, 0));
        for (int i = 0; i < lengthX; ++i) {
            if (obstacleGrid[i][0] == 1)
                break;
            vec[i][0] = 1;
        }
        for (int i = 0; i < lengthY; ++i) {
            if (obstacleGrid[0][i] == 1)
                break;
            vec[0][i] = 1;
        }
        for (int i = 1; i < lengthX; ++i) {
            for (int j= 1; j < lengthY; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
                }
            }
        }
        return vec[lengthX - 1][lengthY - 1];
    }
};