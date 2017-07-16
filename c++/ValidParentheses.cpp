/**
 *
 * Given a string containing just the characters '(', ')',
 * '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}"
 * are all valid but "(]" and "([)]" are not.
 *
 */

#include <string>
#include <stack>
#include <iostream>

using std::string;
using std::stack;

// class Solution {
// public:
//   bool isValid(string s) {
//     stack<char> parentheses;
//     for (const char& c : s) {
//       if (c == '(' || c == '{' || c == '[')
//         parentheses.push(c);
//       if (c == ')' || c == '}' || c == ']') {
//         if (parentheses.empty())
//           return false;
//         if (((c == ')' && parentheses.top() == '(') ||
//              (c == '}' && parentheses.top() == '{') ||
//              (c == ']' && parentheses.top() == '[')) == false)
//           return false;
//         else
//           parentheses.pop();
//       }
//     }
//     return parentheses.empty();
//   }
// };

class Solution {
public:
  bool isValid(string s) {
    stack<char> parentheses;
    for (const char& c : s) {
      if (c == '(')
        parentheses.push(')');
      else if (c == '{')
        parentheses.push('}');
      else if (c == '[')
        parentheses.push(']');
      else {
        /* need to check empty or it will core dumped */
        if (parentheses.empty() || parentheses.top() != c)
          return false;

        parentheses.pop();
      }
    }
    return parentheses.empty();
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  string str("()]");
  string result = test.isValid(str) ? "true" : "false";
  std::cout <<  result << '\n';
  return 0;
}
