/**
 *
 * Write a function to find the longest common prefix string
 * amongst an array of strings.
 *
 */

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
      return "";

    string result;
    for (int i = 0; i < strs[0].size(); ++i) {
      for (int j = 1; j < strs.size(); ++j) {
        /* 有可能不存在这个字符 */
        if (i >= strs[j].size() || strs[0][i] != strs[j][i])
          return result;
      }

      result += strs[0][i];
    }

    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<string> strs {"ac", "ac", "a", "b"};
  std::cout << test.longestCommonPrefix(strs) << std::endl;
  return 0;
}