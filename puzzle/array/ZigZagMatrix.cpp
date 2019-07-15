/* 之字形打印矩阵 */
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
   vector<int> printMatrixZigzag(vector<vector<int>>& matrix) {
       if (matrix.empty())
           return {};
       vector<int> result;
       bool flag = true;
       int firstX = 0, firstY = 0, secondX = 0, secondY = 0;
       int endX = matrix.size() - 1, endY = matrix[0].size() - 1;
       while (firstX <= endX && firstY <= endY) {
           print(matrix, result, firstX, firstY, secondX, secondY, flag);
           firstX = (firstY == endY ? firstX + 1 : firstX);
           firstY = (firstY == endY ? firstY : firstY + 1);
           /* 这里记住要先判断secondY，否则secondX的值可能会被改变，导致判断错误 */
           secondY = (secondX == endX ? secondY + 1 : secondY);
           secondX = (secondX == endX ? secondX : secondX + 1);
           /* 注意这里是逻辑非，不是按位取反 */
           flag = !flag;
       }
       return result;
   }
private:
   void print(vector<vector<int>>& matrix, vector<int>& result, int firstX, int firstY, int secondX, int secondY, bool flag) {
       if (flag) {
           for (int i = secondX, j = secondY; i >= firstX && j <= firstY; --i, ++j)
               result.push_back(matrix[i][j]);
       } else {
           for (int i = firstX, j = firstY; i <= secondX && j >= secondY; ++i, --j)
               result.push_back(matrix[i][j]);
       }
   }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<vector<int>> matrix1{{1,2,3,4},
                               {5,6,7,8},
                               {9,10,11,12}};
    REQUIRE(test.printMatrixZigzag(matrix1) == vector<int>{1,2,5,9,6,3,4,7,10,11,8,12});
    vector<vector<int>> matrix2{{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}};
    REQUIRE(test.printMatrixZigzag(matrix2) == vector<int>{1,2,5,9,6,3,4,7,10,13,14,11,8,12,15,16});
}
