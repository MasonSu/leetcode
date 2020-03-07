// Given a string s, find the longest palindromic substring in s. 
// You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

// 动态规划的扫描方向为从下往上
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int length = s.size();
        vector<vector<int>> vec(length, vector<int>(length));
        for (int i = 0; i < length; ++i)
            vec[i][i] = 1;
        int pos = 0, max = 1;
        for (int i = length - 1; i >= 0; --i) {
            for (int j = i + 1; j < length; ++j) {
                /* 除了判断字符是否一样外，还需判断内侧是不是回文子串 */
                if (s[i] == s[j] && (j - i == 1 || vec[i + 1][j - 1] > 0)) {
                    vec[i][j] = vec[i + 1][j - 1] + 2;
                    if (vec[i][j] > max) {
                        max = vec[i][j];
                        pos = i;
                    }
                }
            }
        }
        return s.substr(pos, max);
    }
};

/* 第二种方法比第一种方法快很多，严格来说都是O(N^2)，
 * 可能是测试用例的问题，导致第二种方法的内部循环只执
 * 行了几步就退出了，而第一种方法会计算一半左右的位置
 */
class Solution2 {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int start = 0, max = 1, low = 0, high = 0, length = s.size();
        for (int i = 1; i < length; ++i) {
            /* 偶数长度 */
            low = i - 1;
            high = i;
            while (low >= 0 && high < length && s[low] == s[high]) {
                low--;
                high++;
            }
            if (high - low - 1 > max) {
                max = high - low - 1;
                start = low + 1;
            }
            /* 奇数长度 */
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < length && s[low] == s[high]) {
                low--;
                high++;
            }
            if (high - low - 1 > max) {
                max = high - low - 1;
                start = low + 1;
            }
        }
        return s.substr(start, max);
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    REQUIRE(test.longestPalindrome("a") == "a");
    REQUIRE(test.longestPalindrome("abcda") == "a");
    REQUIRE(test.longestPalindrome("babad") == "bab");
    REQUIRE(test.longestPalindrome("cbbd") == "bb");
    REQUIRE(test.longestPalindrome("forgeeksskeegfor") == "geeksskeeg");
}
