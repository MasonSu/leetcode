/**
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 */

#include <string>

using std::string;

/*class Solution {
public:
  string addBinary(string a, string b) {
    if (a.empty())
      return b;
    if (b.empty())
      return a;
    string result;
    if (a.size() >= b.size())
      b.insert(0, a.size() - b.size(), '0');
    else
      a.insert(0, b.size() - a.size(), '0');
    int length = a.size() - 1;
    bool one = false;
    while (length >= 0) {
      if (a[length] == '1' && b[length] == '1') {
        if (one)
          result.insert(0, 1, '1');
        else
          result.insert(0, 1, '0');
        one = true;
      } else if (a[length] == '0' && b[length] == '0') {
        if (one)
          result.insert(0, 1, '1');
        else
          result.insert(0, 1, '0');
        one = false;
      } else {
        if (one)
          result.insert(0, 1, '0');
        else
          result.insert(0, 1, '1');
      }
      length--;
    }
    if (one)
      result.insert(0, 1, '1');
    return result;
  }
};*/

class Solution {
public:
  string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, c = 0;
    string s;
    while (i >= 0 || j >= 0 || c == 1) {
      if (i >= 0)
        c += a[i--] - '0';
      if (j >= 0)
        c += b[j--] - '0';
      s = char('0' + c % 2) + s;
      c = c / 2;
    }
    return s;
  }
};
