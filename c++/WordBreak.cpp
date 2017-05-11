/**
 * Given a non-empty string s and a dictionary wordDict
 * containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */

/* Failed */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> vec(s.size() + 1, 0);
    vec[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j)
        if (vec[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
          vec[i] = true;
          break;
        }
    }
    return vec[s.size()];
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<string> vec{"leet", "code"};
  std::cout << test.wordBreak("leetcode", vec) << '\n';
  return 0;
}