// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// Example 1:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
        int lengthX = s1.size(), lengthY = s2.size();
        vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
        vec[0][0] = 1;
        for (int i = 1; i <= lengthY; ++i) {
            if (s2[i - 1] == s3[i - 1])
                vec[0][i] = vec[0][i - 1];
        }
        for (int i = 1; i <= lengthX; ++i) {
            if (s1[i - 1] == s3[i - 1])
                vec[i][0] = vec[i - 1][0];
        }
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                if (s3[i + j - 1] == s1[i - 1])
                    vec[i][j] = vec[i][j] || vec[i - 1][j];
                if (s3[i + j - 1] == s2[j - 1])
                    vec[i][j] = vec[i][j] || vec[i][j - 1];
            }
        }
        return vec[lengthX][lengthY];
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    string s1("aabcc"), s2("dbbca"), s3("aadbbcbcac");
    REQUIRE(test.isInterleave(s1, s2, s3) == true);
    s3 = "aadbbbaccc";
    REQUIRE(test.isInterleave(s1, s2, s3) == false);
}
