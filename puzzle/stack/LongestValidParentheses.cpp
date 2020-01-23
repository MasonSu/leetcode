// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:

// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

#define CATCH_CONFIG_MAIN 
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        /* stack中存放'('的下标 */
        stack<int> st;
        st.push(-1);
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                st.pop();
                 /* 当栈为空时，为有效子串的前一个坐标 */
                if (st.empty()) {
                    st.push(i);
                } else {
                    result = std::max(result, i - st.top());
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
          return 0;
        int result = 0, length = s.size();
        vector<int> vec(length);
        for (int i = 1; i < length; ++i) {
          if (s[i] == ')') {
            if (s[i - 1] == '(') {
              vec[i] = (i >= 2 ? vec[i - 2] + 2 : 2);
            } else {
              int j = i - 1 - vec[i - 1];
              if (j >= 0 && s[j] == '(') {
                vec[i] = vec[i - 1] + 2;
                vec[i] += (i - vec[i] >= 0 ? vec[i - vec[i]] : 0);
              }
            }
            result = std::max(result, vec[i]);
          }
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    REQUIRE(test.longestValidParentheses(")()())") == 4);
    REQUIRE(test.longestValidParentheses("(()(") == 2);
    REQUIRE(test.longestValidParentheses("()(()))))") == 6);
    REQUIRE(test.longestValidParentheses("(())(()") == 4);
    REQUIRE(test.longestValidParentheses("(()))))()()(())") == 8);
}
