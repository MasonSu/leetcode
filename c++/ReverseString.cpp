/** 
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
  string reverseString(string s) {
    if (s.empty())
      return s;
    string::iterator first = s.begin(), second = s.end() - 1;
    while (first < second) {
      char c = *first;
      *first++ = *second;
      *second-- = c;
    }
    return s;
  }
};