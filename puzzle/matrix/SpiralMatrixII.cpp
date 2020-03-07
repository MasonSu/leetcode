// Given a positive integer n, generate a square matrix 
// filled with elements from 1 to n2 in spiral order.

// Example:

// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0)
            return {};
        int startX = 0, startY = 0, endX = n - 1, endY = n - 1;
        int num = 1;
        vector<vector<int>> result(n, vector<int>(n));
        while (startX <= endX) {
            generate(result, startX++, startY++, endX--, endY--, num);
        }
        return result;
    }
    
private:
    void generate(vector<vector<int>>& matrix, int startX, int startY, int endX, int endY, int& num) {
        if (startX == endX && startY == endY) {
            matrix[startX][startY] = num;
            return;
        }
        for (int i = startY; i < endY; ++i)
            matrix[startX][i] = num++;
        for (int i = startX; i < endX; ++i)
            matrix[i][endY] = num++;
        for (int i = endY; i > startY; --i)
            matrix[endX][i] = num++;
        for (int i = endX; i > startX; --i)
            matrix[i][startY] = num++;
    }
};