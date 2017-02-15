/**
 *
 * Given a string s consists of upper/lower-case alphabets and empty
 * space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 *
 */

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int i = s.size() - 1;
    /* Ignore the tailing whitespace */
    while (i >= 0 && s[i] == ' ')
      i--;

    int count = 0;
    while (i >= 0 && s[i] != ' ') {
      count++;
      i--;
    }    
    return count;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  cout << test.lengthOfLastWord("Hello World") << '\n';
  return 0;
}