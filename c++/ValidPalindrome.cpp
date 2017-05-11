/**
 * Given a string, determine if it is a palindrome,
 * considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 */

#include <iostream>
#include <string>
#include <cctype>

using std::string;

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.empty())
      return true;
    for (int first = 0, second = s.size() - 1; first < second; ++first, --second) {
      /* in case ",,,,," */
      while (!std::isalnum(s[first]) && first < second)
        ++first;
      while (!std::isalnum(s[second]) && first < second)
        --second;
      if (std::toupper(s[first]) != std::toupper(s[second]))
        return false;
    }
    return true;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.isPalindrome("a.") << '\n';
  return 0;
}