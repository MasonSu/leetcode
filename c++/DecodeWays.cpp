/**
 * A message containing letters from A-Z is being encoded to
 * numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 *
 */

#include <string>

using std::string;

class Solution {
public:
  int numDecodings(string s) {
    if (s.empty())
      return 0;

    int length = s.size(), arr[length + 1];
    arr[0] = 1;
    arr[1] = s[0] == '0' ? 0 : 1;

    for (int i = 2; i < length + 1; ++i) {
      /* current position */
      if (s[i - 1] == '0') {
        /* invalid input */
        if (s[i - 2] != '1' && s[i - 2] != '2')
          return 0;
        arr[i] = arr[i - 2];
      }
      else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] - '0' <= 6))
        arr[i] = arr[i - 1] + arr[i - 2];
      else
        arr[i] = arr[i - 1];
    }

    return arr[length];
  }
};