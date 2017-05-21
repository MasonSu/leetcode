/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 *
 * Some examples:
 *  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for (auto str : tokens) {
      if (str == "+" || str == "-" || str == "*" || str == "/") {
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        /* switch only accept integers type */
        if (str == "+")
          nums.push(num2 + num1);
        else if (str == "-")
          nums.push(num2 - num1);
        else if (str == "*")
          nums.push(num2 * num1);
        else if (str == "/")
          nums.push(num2 / num1);
      } else {
        nums.push(std::stoi(str));
      }
    }
    return nums.top();
  }
};