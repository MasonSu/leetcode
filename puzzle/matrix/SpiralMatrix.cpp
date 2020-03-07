// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

/* 转圈打印矩阵 */
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int startX = 0, startY = 0, endX = matrix.size() - 1, endY = matrix[0].size() - 1;
        vector<int> result;
        while (startX <= endX && startY <= endY) {
            spiral(matrix, result, startX++, startY++, endX--, endY--);
        }
        return result;
    }
    
private:
    void spiral(vector<vector<int>>& matrix, vector<int>& result, 
                int startX, int startY, int endX, int endY) {
        if (startX == endX) {
            for (int i = startY; i <= endY; ++i)
                result.push_back(matrix[startX][i]);
            return;
        }
        if (startY == endY) {
            for (int i = startX; i <= endX; ++i)
                result.push_back(matrix[i][startY]);
            return;
        }
        for (int i = startY; i < endY; ++i)
            result.push_back(matrix[startX][i]);
        for (int i = startX; i < endX; ++i)
            result.push_back(matrix[i][endY]);
        for (int i = endY; i > startY; --i)
            result.push_back(matrix[endX][i]);
        for (int i = endX; i > startX; --i)
            result.push_back(matrix[i][startY]);
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<vector<int>> matrix1 = {{1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,16}};
    REQUIRE(test.spiralOrder(matrix1) == vector<int>{1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10});
    vector<vector<int>> matrix2 = {{1,2,3},
                                   {4,5,6},
                                   {7,8,9}};
    REQUIRE(test.spiralOrder(matrix2) == vector<int>{1,2,3,6,9,8,7,4,5});
    vector<vector<int>> matrix3 = {{1,2,3,4},
                                   {5,6,7,8}};
    REQUIRE(test.spiralOrder(matrix3) == vector<int>{1,2,3,4,8,7,6,5});
    vector<vector<int>> matrix4 = {{1,2,3},
                                   {4,5,6},
                                   {7,8,9},
                                   {10,11,12},
                                   {13,14,15}};
    REQUIRE(test.spiralOrder(matrix4) == vector<int>{1,2,3,6,9,12,15,14,13,10,7,4,5,8,11});
    vector<vector<int>> matrix5 = {{1,2,3,4,5},
                                   {6,7,8,9,10},
                                   {11,12,13,14,15}};
    REQUIRE(test.spiralOrder(matrix5) == vector<int>{1,2,3,4,5,10,15,14,13,12,11,6,7,8,9});

}
