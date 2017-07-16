/**
 * Given two strings s and t, write a function to
 * determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would
 * you adapt your solution to such case?
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    vector<int> table(128, 0);
    for (int i = 0; i < s.size(); ++i) {
      table[s[i]]++;
      table[t[i]]--;
    }

    for (auto iter = table.begin(); iter != table.end(); ++iter)
      if (*iter != 0)
        return false;

    return true;
  }
};