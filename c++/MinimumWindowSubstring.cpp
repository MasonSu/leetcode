/**
 * Given a string S and a string T, find the minimum window in
 * S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T,
 * return the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there
 * will always be only one unique minimum window in S.
 */

#include <iostream>
#include <string>

using std::string;

/* Time Limit Exceeded */
/*class Solution {
public:
  string minWindow(string s, string t) {
    if (s.empty() || s.size() < t.size())
      return "";

    string result;
    int first = 0, second = t.size();

    while (1) {
      if ((second == s.size() && second - first < t.size()))
        break;

      if (second - first < t.size()) {
        second++;
        continue;
      }

      string str = s.substr(first, second - first);
      int hashTable[128] = {0};
      bool found = 1;

      for (auto c : t)
        hashTable[c]++;

      for (auto c : str)
        hashTable[c]--;

      for (auto c : t) {
        if (hashTable[c] > 0) {
          if (second == s.size())
            return result;
          second++;
          found = 0;
          break;
        }
      }

      if (found) {
        first++;
        if (result.empty() || str.size() < result.size())
          result = str;
      }
    }

    return result;
  }
};*/

class Solution {
public:
  string minWindow(string s, string t) {
    int hashTable[128] = {0};
    for (auto c : t)
      hashTable[c]++;

    int count = t.size(), length = 0, minStart = 0;

    for (int start = 0, end = 0; end < s.size(); ++end) {
      if (hashTable[s[end]] > 0)
        count--;

      hashTable[s[end]]--;

      while (count == 0) {
        if (length == 0 || end + 1 - start < length) {
          minStart = start;
          length = end + 1 - start;
        }

        hashTable[s[start]]++;
        if (hashTable[s[start]] > 0)
          count++;
        start++;
      }
    }

    return s.substr(minStart, length);
  }
};

int main(int argc, char const *argv[]) {
  Solution test;
  std::cout << test.minWindow("AABC", "ABC") << '\n';
  return 0;
}