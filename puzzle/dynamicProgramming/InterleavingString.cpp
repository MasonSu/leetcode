#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        int lengthX = s1.size(), lengthY = s2.size();
        vector<vector<int>> vec(lengthX, vector<int>(lengthY, -1));
        return dfs(s1, s2, s3, vec, lengthX - 1, lengthY - 1, s3.size() - 1);

    }
private:
    bool dfs(string& s1, string& s2, string& s3, vector<vector<int>>& vec, int first, int second, int third) {
        if (third == -1)
            return true;
        if (first >= 0 && second >= 0) {
            if (vec[first][second] == -1) {
                if (s1[first] == s3[third] && s2[second] == s3[third]) {
                    vec[first][second] = dfs(s1, s2, s3, vec, first - 1, second, third - 1) ||
                            dfs(s1, s2, s3, vec, first, second - 1, third - 1);
                } else if (s1[first] == s3[third]) {
                    vec[first][second] = dfs(s1, s2, s3, vec, first - 1, second, third - 1);
                } else if (s2[second] == s3[third]) {
                    vec[first][second] = dfs(s1, s2, s3, vec, first, second - 1, third - 1);
                } else {
                    vec[first][second] = false;
                }
            }
            return vec[first][second];
        } else if (first == -1) {
            return s2.substr(0, second + 1) == s3.substr(0, third + 1);
        } else if (second == -1) {
            return s1.substr(0, first + 1) == s3.substr(0, third + 1);
        }
    }
};

class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        int lengthX = s1.size(), lengthY = s2.size();
        vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
        vec[0][0] = 1;
        for (int i = 1; i <= lengthX; ++i) {
             vec[i][0] = vec[i - 1][0] && (s1[i - 1] == s3[i - 1]);
             if (vec[i][0] == 0)
                 break;
        }
        for (int j = 1; j <= lengthY; ++j) {
            vec[0][j] = vec[0][j - 1] && (s2[j - 1] == s3[j - 1]);
            if (vec[0][j] == 0)
                break;
        }
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                if (s3[i + j - 1] == s1[i - 1] && s3[i + j - 1] == s2[j - 1])
                    vec[i][j] = vec[i - 1][j] || vec[i][j - 1];
                else if (s3[i + j - 1] == s1[i - 1])
                    vec[i][j] = vec[i - 1][j];
                else if (s3[i + j - 1] == s2[j - 1])
                    vec[i][j] = vec[i][j - 1];
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
