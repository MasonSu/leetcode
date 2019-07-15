#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        /* stack中存放'('的坐标 */
        stack<int> st;
        /* last最开始设为-1，当栈为空时，为有效子串的前一个坐标 */
        int last = -1, result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
               if (st.empty()) {
                   last = i;
               } else {
                   st.pop();
                   if (st.empty())
                       result = std::max(result, i - last);
                   else
                       result = std::max(result, i - st.top());
               }
            }
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    REQUIRE(test.longestValidParentheses(")()())") == 4);
    REQUIRE(test.longestValidParentheses("(()(") == 2);
    REQUIRE(test.longestValidParentheses("()(()))))") == 6);
    REQUIRE(test.longestValidParentheses("(())(()") == 4);
    REQUIRE(test.longestValidParentheses("(()))))()()(())") == 8);
}
