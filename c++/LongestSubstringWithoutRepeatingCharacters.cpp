/**
 * Given a string, find the length of the longest substring
 * without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 */

/* Failed */
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> hashTable(128, -1);
    int length = 0;
    for (int start = 0, end = 0; end < s.size(); ++end) {
      if (hashTable[s[end]] != -1 && hashTable[s[end]] + 1 > start)
        start = hashTable[s[end]] + 1;

      hashTable[s[end]] = end;

      if (end + 1 - start > length)
        length = end + 1 - start;
    }

    return length;
  }
};

int main(int argc, char const *argv[]) {
  Solution test;
  test.lengthOfLongestSubstring("abba");
  return 0;
}