/**
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
  void reverseWords(string &s) {
    if (s.empty())
      return;
    /* erase leading spaces */
    string::iterator iter = s.begin();
    while (*iter == ' ')
      iter = s.erase(iter);
    reverse(s.begin(), s.end() - 1);
    iter = s.begin();
    while (*iter != '\0') {
      while (*iter == ' ')
        iter = s.erase(iter);
      string::iterator tmp = iter;
      do {
        ++iter;
      } while (*iter != ' ' && *iter != '\0');
      reverse(tmp, iter - 1);
      if (*iter == '\0')
        break;
      ++iter;
    }
  }

private:
  void reverse(string::iterator begin, string::iterator end) {
    while (begin < end) {
      char c = *begin;
      *begin++ = *end;
      *end-- = c;
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  string str("  the  sky is blue  ");
  test.reverseWords(str);
  std::cout << str << '\n';
  return 0;
}