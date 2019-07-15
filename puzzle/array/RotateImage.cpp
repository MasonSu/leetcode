/* 正方形矩阵顺时针转动90度 */
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int start = 0, end = matrix.size() - 1;
        while (start < end) {
            rotateMatrix(matrix, start, end);
            start++;
            end--;
        }
        return matrix;
    }
private:
    void rotateMatrix(vector<vector<int>>& matrix, int start, int end) {
        for (int i = 0; i < end - start; ++i) {
            int tmp = matrix[start][start + i];
            matrix[start][start + i] = matrix[end - i][start];
            matrix[end - i][start] = matrix[end][end - i];
            matrix[end][end - i] = matrix[start + i][end];
            matrix[start + i][end] = tmp;
        }
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<vector<int>> matrix1 = {{1,2},
                                   {3,4}};
    REQUIRE(test.rotate(matrix1) == vector<vector<int>>{{3,1},
                                                        {4,2}});
    vector<vector<int>> matrix2 = {{1,2,3},
                                   {4,5,6},
                                   {7,8,9}};
    REQUIRE(test.rotate(matrix2) == vector<vector<int>>{{7,4,1},
                                                        {8,5,2},
                                                        {9,6,3}});
    vector<vector<int>> matrix3 = {{1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,16}};
    REQUIRE(test.rotate(matrix3) == vector<vector<int>>{{13,9,5,1},
                                                        {14,10,6,2},
                                                        {15,11,7,3},
                                                        {16,12,8,4}});
}
