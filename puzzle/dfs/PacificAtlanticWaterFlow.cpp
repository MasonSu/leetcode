// Given an m x n matrix of non-negative integers representing the height of each unit cell in a 
// continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic 
// ocean" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one 
// with height equal or lower.

// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

// Note:

// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
 

// Example:

// Given the following 5x5 matrix:

//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic

// Return:

// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

// 分别从4个边界开始，从外向内流动，判断的条件改为当前值不大于下一个值，这样下一个
// 值保证可以抵达到边界，对于pacific和atlantic相交的数据就是能够同时抵达两边的数据
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        int lengthX = matrix.size(), lengthY = matrix[0].size();
        vector<vector<int>> pacific(lengthX, vector<int>(lengthY)), atlantic(lengthX, vector<int>(lengthY));
        
        for (int i = 0; i < lengthX; ++i) {
        	// 最左端开始 
            dfs(matrix, pacific, INT_MIN, i, 0);
            // 最右端开始
            dfs(matrix, atlantic, INT_MIN, i, lengthY - 1);
        }
        
        for (int i = 0; i < lengthY; ++i) {
            // 最顶端开始
            dfs(matrix, pacific, INT_MIN, 0, i);
            // 最底端开始
            dfs(matrix, atlantic, INT_MIN, lengthX - 1, i);
        }

        vector<vector<int>> result;
        for (int i = 0; i < lengthX; ++i) {
            for (int j = 0; j < lengthY; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visted, int value, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size() 
            || visted[i][j] || value > matrix[i][j])
            return;
        visted[i][j] = 1;
        dfs(matrix, visted, matrix[i][j], i + 1, j);
        dfs(matrix, visted, matrix[i][j], i - 1, j);
        dfs(matrix, visted, matrix[i][j], i, j + 1);
        dfs(matrix, visted, matrix[i][j], i, j - 1);
    }
};