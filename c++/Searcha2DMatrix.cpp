/**
 * Write an efficient algorithm that searches for a value
 * in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer
 * of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty())
      return false;
    int height = matrix.size(), length = matrix[0].size();
    int low = 0, high = height * length - 1;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (matrix[middle / length][middle % length] > target)
        high = middle - 1;
      else if (matrix[middle / length][middle % length] < target)
        low = middle + 1;
      else
        return true;
    }
    return false;
  }
};