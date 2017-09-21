/**
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent
 * cell, where "adjacent" cells are those horizontally or vertically
 * neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

/* Failed */
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty())
      return false;

    int yLength = board.size(), xLength = board[0].size();
    vector<vector<int>> visted(yLength, vector<int>(xLength));

    for (int i = 0; i < yLength; ++i)
      for (int j = 0; j < xLength; ++j)
        if (isExist(board, word, visted, i, j, 0))
          return true;
    return false;
  }

private:
  bool isExist(vector<vector<char>>& board, string word, vector<vector<int>>& visted, int col, int row, int length) {
    if (length == word.size())
      return true;

    if (col < 0 || col >= board.size() || row < 0 || row >= board[0].size())
      return false;

    if (visted[col][row])
      return false;

    if (board[col][row] != word[length])
      return false;

    visted[col][row] = 1;
    bool found = isExist(board, word, visted, col - 1, row, length + 1) ||
                 isExist(board, word, visted, col + 1, row, length + 1) ||
                 isExist(board, word, visted, col, row - 1, length + 1) ||
                 isExist(board, word, visted, col, row + 1, length + 1);
    visted[col][row] = 0;
    return found;
  }
};