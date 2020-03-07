// Given a string s, find the longest palindromic subsequence's 
// length in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
// Example 2:
// Input:

// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty())
            return 0;
        string rs = s;
        std::reverse(rs.begin(), rs.end());
        int length = s.size();
        vector<vector<int>> vec(length + 1, vector<int>(length + 1));
        for (int i = 1; i <= length; ++i) {
            for (int j = 1; j <= length; ++j) {
                if (s[i - 1] == rs[j - 1]) {
                    vec[i][j] = vec[i - 1][j - 1] + 1;
                } else {
                    vec[i][j] = std::max(vec[i - 1][j], vec[i][j - 1]);
                }
            }
        }
        return vec[length][length];
    }
};

class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty())
            return 0;
        int length = s.size();
        vector<vector<int>> vec(length, vector<int>(length, -1));
        dfs(s, 0, length - 1, vec);
        return vec[0][length - 1];
    }
private:
    int dfs(string& s, int i, int j, vector<vector<int>>& vec) {
        if (i > j)
            return 0;
        if (i == j)
            vec[i][j] = 1;
        if (vec[i][j] == -1) {
            if (s[i] == s[j])
                vec[i][j] = dfs(s, i + 1, j - 1, vec) + 2;
            else
                vec[i][j] = std::max(dfs(s, i + 1, j, vec), dfs(s, i, j - 1, vec));
        }
        return vec[i][j];
    }
};

class Solution3 {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty())
            return 0;
        int length = s.size();
        vector<vector<int>> vec(length, vector<int>(length));
        for (int i = 0; i < length; ++i)
            vec[i][i] = 1;
        for (int i = length - 1; i >= 0; --i) {
            for (int j = i + 1; j < length; ++j) {
                if (s[i] == s[j]) {
                    vec[i][j] = vec[i + 1][j - 1] + 2;
                } else {
                    vec[i][j] = std::max(vec[i + 1][j], vec[i][j - 1]);
                }
            }
        }
        return vec[0][length - 1];
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    REQUIRE(test.longestPalindromeSubseq("bbbab") == 4);
    REQUIRE(test.longestPalindromeSubseq("cbbd") == 2);
    REQUIRE(test.longestPalindromeSubseq("a") == 1);
}
