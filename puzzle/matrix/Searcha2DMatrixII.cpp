// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// Example:

// Consider the following matrix:

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.

// Given target = 20, return false.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int lengthX = matrix.size() - 1, lengthY = matrix[0].size() - 1,
            startX = 0, startY = lengthY;
        while (startX <= lengthX && startY >= 0) {
            if (matrix[startX][startY] < target) {
                startX++;
            } else if (matrix[startX][startY] > target) {
                startY--;
            } else {
                return true;
            }
        }
        return false;
    }
};