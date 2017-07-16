/**
 * Given a string s and a non-empty string p, find
 * all the start indices of p's anagrams in s.
 *
 * Strings consists of lowercase English letters
 * only and the length of both strings s and p will
 * not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> hash(256, 0);

    for (auto c : p)
      hash[c]++;

    int left = 0, right = 0, count = p.size();
    vector<int> result;

    while (right < s.length()) {
      if (hash[s[right]] >= 1) {
        count--;
      }

      hash[s[right]]--;
      right++;
      std::cout << "before count is " << count << '\n';
      if (count == 0)
        result.push_back(left);

      if (right - left == p.length()) {
        if (hash[s[left]] >= 0)
          count++;

        hash[s[left]]++;
        left++;
      }

      std::cout << "after  count is " << count << '\n';
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<int> result;
  result = test.findAnagrams("cbaebabacd", "abc");
  return 0;
}