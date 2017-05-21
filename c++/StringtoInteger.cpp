/**
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases.
 * If you want a challenge, please do not see below
 * and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely
 * (ie, no given input specs). You are responsible to gather all
 * the input requirements up front.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <climits>

using std::string;

/*class Solution {
public:
  int myAtoi(string str) {
    long long num = 0;
    bool firstBit = true, negative = false;
    for (auto c : str) {
      if (c == '+' || c == '-' || std::isdigit(c)) {
        if (firstBit) {
          if (c == '-')
            negative = true;
          else if (std::isdigit(c))
            num = c - '0';
          firstBit = false;
        } else {
          if (!std::isdigit(c))
            return num;
          else {
            if (negative)
              num = num * 10 - (c - '0');
            else
              num = num * 10 + c - '0';

            if (num >= INT_MAX)
              return INT_MAX;
            else if (num <= INT_MIN)
              return INT_MIN;
          }
        }
      } else {
        if (firstBit && c == ' ')
          continue;
        return num;
      }
    }
    return num;
  }
};*/

class Solution {
public:
  int myAtoi(string str) {
    long long num = 0;
    int index = 0;
    while (index < str.size()) {
      if (str[index] == ' ')
        index++;
      else
        break;
    }
    int multipiler = 1;
    if (str[index] == '+' || str[index] == '-')
      multipiler = str[index++] == '+' ? 1 : -1;
    while (std::isdigit(str[index])) {
      num = num * 10 + multipiler * (str[index] - '0');
      if (num >= INT_MAX)
        return INT_MAX;
      if (num <= INT_MIN)
        return INT_MIN;
      index++;
    }
    return num;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.myAtoi("-2147483647") << '\n';
  return 0;
}