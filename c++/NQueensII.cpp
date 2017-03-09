/**
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total 
 * number of distinct solutions.
 *
 */

#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
  int totalNQueens(int n) {
    vector<int> vec;
    int count = 0;
    queen(vec, n, 0, count);
    return count;
  }

private:
  void queen(vector<int>& tmp, int n, int row, int &count) {
    if (row == n) {
      count++;
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (isValid(tmp, col, row)) {
        tmp.push_back(col);
        queen(tmp, n, row + 1, count);
        tmp.pop_back();
      }
    }
  }

  bool isValid(const vector<int>& tmp, int value, int row) {
    for (int i = 0; i < row; ++i) 
      if (tmp[i] == value || std::abs(value - tmp[i]) == std::abs(row - i))
        return false;   
    return true;
  }
};