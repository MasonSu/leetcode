/**
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces . The integer division should truncate toward zero.
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 *
 *   "3+2*2" = 7
 *   " 3/2 " = 1
 *   " 3+5 / 2 " = 5
 *
 * Note: Do not use the eval built-in library function.
 *
 */

#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <cctype>

using std::cout;
using std::string;
using std::deque;
using std::stack;

/*class Solution {
public:
  int calculate(string s) {
    string operators;
    deque<int> numbers;
    for (string::iterator iter = s.begin(); iter != s.end(); ) {
      if (*iter == ' ') {
        ++iter;
        continue;
      }
      if (*iter - '0' >= 0 && *iter - '0' <= 9) {
        int num = *iter - '0';
        ++iter;
        while (*iter - '0' >= 0 && *iter - '0' <= 9) {
          num = num * 10 + (*iter - '0');
          ++iter;
        }
        numbers.push_back(num);
      }
      else {
        if (*iter == '+' || *iter == '-') {
          operators += *iter;
          ++iter;
        }
        else if (*iter == '*' || *iter == '/') {
          char symbol = *iter;
          do {
            ++iter;
          } while (*iter == ' ');
          if (*iter - '0' >= 0 && *iter - '0' <= 9) {
            int num = *iter - '0';
            ++iter;
            while (*iter - '0' >= 0 && *iter - '0' <= 9) {
              num = num * 10 + (*iter - '0');
              ++iter;
            }
            int privNum = numbers.back();
            numbers.pop_back();
            if (symbol == '*')
              numbers.push_back(privNum * num);
            else if (symbol == '/')
              numbers.push_back(privNum / num);
          }
        }
      }
    }
    int result = numbers.front(), index = 0;
    numbers.pop_front();
    while (numbers.size() && index < operators.size()) {
      if (operators[index] == '+')
        result += numbers.front();
      else if (operators[index] == '-')
        result -= numbers.front();

      numbers.pop_front();
      index++;
    }
    return result;
  }
};*/

class Solution {
public:
  int calculate(string s) {
    stack<int> numbers;
    char preOperator = '+';
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (std::isdigit(s[i]))
        num = num * 10 + (s[i] - '0');
      /* + - * / */
      if (i == s.size() - 1 || (!std::isdigit(s[i]) && s[i] != ' ')) {
        if (preOperator == '+')
          numbers.push(num);
        else if (preOperator == '-')
          numbers.push(-num);
        else {
          int top = numbers.top();
          numbers.pop();
          if (preOperator == '*')
            numbers.push(top * num);
          else if (preOperator == '/')
            numbers.push(top / num);
        }
        /* update operator */
        preOperator = s[i];
        num = 0;
      }
    }
    int result = 0;
    while (numbers.size()) {
      result += numbers.top();
      numbers.pop();
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  cout << test.calculate("12 + 2 3 ") << '\n';
  return 0;
}