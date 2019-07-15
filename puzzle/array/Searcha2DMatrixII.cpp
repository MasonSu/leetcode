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