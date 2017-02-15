/**
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on
 * a given number of rows like this: (you may want to display this
 * pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 */

/* Failed */
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    vector<string> result(numRows, "");   /* Initialization */
    int row = 0, step = 1;
    for (int i = 0; i < s.size(); ++i) {
      result[row] += s[i];
      if (row == 0)
        step = 1;
      else if (row == numRows - 1)
        step = -1;
      row += step;
    }
    string res;
    for (const string& s : result)
      res += s;
    return res;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  cout << test.convert("PAYPALISHIRING", 3) << '\n';
  return 0;
}