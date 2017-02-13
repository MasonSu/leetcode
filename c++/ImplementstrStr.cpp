/**
 *
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 *
 */

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty())
      return 0;
    if (haystack.size() < needle.size())
      return -1;
    int length = needle.size();
    /*string substr;
    for (int i = 0; i < haystack.size() - length + 1; ++i) {
      substr.assign(haystack, i, length);
      if (substr == needle)
        return i;
    }*/
    for (int i = 0; i < haystack.size() - length + 1; ++i) {
      int j = 0;
      for (; j < length; ++j) {
        if (haystack[i + j] != needle[j])
          break;
      }
      if (j == length)
        return i;
    }
    return -1;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  string str1("adcbcbad"), str2("cba");
  cout << test.strStr(str1, str2) << '\n';
  return 0;
}