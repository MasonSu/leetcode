/**
 *
 * Given n pairs of parentheses, write a function to generate all 
 * combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 *
 */

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::stack;

/*class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string tmp;
    parenthesis(result, tmp, 0, 2 * n);
    return result;
  }

private:
  void parenthesis(vector<string>& result, string &tmp, int length, int count) {
    if (length == count) {
      result.push_back(tmp);
      return;
    }
    string s("()");
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' && std::count(tmp.begin(), tmp.end(), '(') == count / 2)
        continue;
      if (isValid(tmp, s[i])) {
        tmp.push_back(s[i]);
        parenthesis(result, tmp, length + 1, count);
        tmp.pop_back();
      }
    }
  }

  bool isValid(string str, char c) {
    if (c == '(')
      return true;
    str.push_back(c);
    stack<char> st;
    for (const char c : str) {
      if (c == '(')
        st.push(c);
      else if (c == ')') {
        if (st.empty() || st.top() == ')') {
          str.pop_back();
          return false;
        }
        else if (st.top() == '(')
          st.pop();
      }
    }
    str.pop_back();
    return true;
  }
};*/

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string str;
    parenthesis(result, str, 0, 0, n);
    return result;
  }

private:
  void parenthesis(vector<string>& result, string str, int left, int right, int length) {
    if (left == length && right == length) {
      result.push_back(str);
      return;
    }
    if (left < length) 
      parenthesis(result, str + '(', left + 1, right, length);
    
    if (right < left) 
      parenthesis(result, str + ')', left, right + 1, length);
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<string> result = test.generateParenthesis(3);
  for (const string str : result)
    std::cout << str << '\n';
  return 0;
}