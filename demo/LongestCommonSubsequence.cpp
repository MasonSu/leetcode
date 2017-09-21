#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::set;

/* 输出一个子串 */
class Solution {
public:
  string longestCommonSubsequence(string A, string B) {
    int xLength = A.size(), yLength = B.size();
    int arr[xLength + 1][yLength + 1];

    for (int i = 0; i <= yLength; ++i)
      arr[0][i] = 0;

    for (int j = 0; j <= xLength; ++j)
      arr[j][0] = 0;

    for (int i = 1; i <= xLength; ++i) {
      for (int j = 1; j <= yLength; ++j) {
        if (A[i - 1] == B[j - 1])
          arr[i][j] = arr[i - 1][j - 1] + 1;
        else
          arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
      }
    }

    int size = arr[xLength][yLength];
    string LCS(size, '0');
    size--;

    for (int i = xLength, j = yLength; i > 0 && j > 0; ) {
      if (A[i - 1] == B[j - 1]) {
        LCS[size--] = A[i - 1];
        i--;
        j--;
      } else {
        if (arr[i - 1][j] > arr[i][j - 1])
          i--;
        else
          j--;
      }
    }

    return LCS;
  }
};

/* 输出所有子串 */
class Solution2 {
public:
  set<string> LCS(const string& A, const string& B) {
    lengthOfLCS(A, B);

    vector<string> vec = getLCS(A, B, A.length(), B.length());

    set<string> result(make_move_iterator(vec.begin()), make_move_iterator(vec.end()));

    return result;
  }

  vector<string> getLCS(const string& A, const string& B, int m, int n) {
    if (m == 0 || n == 0)
      return {""};

    if (A[m - 1] == B[n - 1]) {
      vector<string> str = getLCS(A, B, m - 1, n - 1);

      for (string &s : str)
        s += A[m - 1];

      return str;
    } else {
      if (table[m - 1][n] > table[m][n - 1])
        return getLCS(A, B, m - 1, n);
      else if (table[m - 1][n] < table[m][n - 1])
        return getLCS(A, B, m, n - 1);
      else {
        vector<string> top = getLCS(A, B, m - 1, n);
        vector<string> left = getLCS(A, B, m, n - 1);

        top.insert(top.end(), left.begin(), left.end());

        return top;
      }
    }
  }

  int lengthOfLCS(const string& A, const string& B) {
    int xLength = A.size(), yLength = B.size();

    table = vector<vector<int>>(xLength + 1, vector<int>(yLength + 1));

    for (int i = 0; i <= yLength; ++i)
      table[0][i] = 0;

    for (int j = 0; j <= xLength; ++j)
      table[j][0] = 0;

    for (int i = 1; i <= xLength; ++i) {
      for (int j = 1; j <= yLength; ++j) {
        if (A[i - 1] == B[j - 1])
          table[i][j] = table[i - 1][j - 1] + 1;
        else
          table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
      }
    }

    return table[xLength][yLength];
  }

private:
  vector<vector<int>> table;
};