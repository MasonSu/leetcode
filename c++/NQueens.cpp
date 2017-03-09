/**
 *
 * The n-queens puzzle is the problem of placing n queens
 * on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *
 */

#include <vector>
#include <string>
#include <cmath>

using std::string;
using std::vector;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string> > result;
    vector<string> tmp;
    queen(result, tmp, n, 0);
    return result;
  }

private:
  void queen(vector<vector<string> >& result, vector<string>& tmp, int n, int row) {
    if (row == n) {
      result.push_back(tmp);
      return;
    }
    for (int col = 0; col < n; ++col) {
      string s(n, '.');
      s[col] = 'Q';
      if (isValid(tmp, col, row)) {
        tmp.push_back(s);
        queen(result, tmp, n, row + 1);
        tmp.pop_back();
      }
    }
  }

  bool isValid(const vector<string>& tmp, int value, int row) {
    for (int i = 0; i < row; ++i) {
      int pos1 = tmp[i].find('Q'), pos2 = value;
      if (pos1 == pos2 || std::abs(pos2 - pos1) == std::abs(row - i))
        return false;
    }
    return true;
  }
};