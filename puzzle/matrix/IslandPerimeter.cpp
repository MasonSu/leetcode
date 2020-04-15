// You are given a map in form of a two-dimensional integer grid where 1 
// represents land and 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The 
// grid is completely surrounded by water, and there is exactly one island 
// (i.e., one or more connected land cells).

// The island doesn't have "lakes" (water inside that isn't connected to 
// the water around the island). One cell is a square with side length 1. 
// The grid is rectangular, width and height don't exceed 100. Determine 
// the perimeter of the island.


// Example:

// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Output: 16

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int count = 0, lengthX = grid.size(), lengthY = grid[0].size();
        for (int i = 0; i < lengthX; ++i) {
            for (int j = 0; j < lengthY; ++j) {
                if (grid[i][j]) {
                    if (i == 0 || grid[i - 1][j] == 0)
                        count++;
                    if (j == 0 || grid[i][j - 1] == 0)
                        count++;
                    if (i == lengthX - 1 || grid[i + 1][j] == 0)
                        count++;
                    if (j == lengthY - 1 || grid[i][j + 1] == 0)
                        count++;
                }
            }
        }
        return count;
    }
};