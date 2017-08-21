/**
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
 * 如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次
 * 打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  vector<int> printMatrix(vector<vector<int> > matrix) {
    if (matrix.empty())
      return {};

    int row = matrix.size(), column = matrix[0].size();
    int left = 0, right = column - 1, up = 0, down = row - 1;
    vector<int> result;

    while (left <= right && up <= down) {
      for (int i = left; i <= right; ++i)
        result.push_back(matrix[up][i]);

      for (int j = up + 1; j <= down; ++j)
        result.push_back(matrix[j][right]);

      if (down > up)
        for (int i = right - 1; i >= left; --i)
          result.push_back(matrix[down][i]);

      if (right > left)
        for (int j = down - 1; j > up; --j)
          result.push_back(matrix[j][left]);

      left++, right--, up++, down--;
    }

    return result;
  }
};

