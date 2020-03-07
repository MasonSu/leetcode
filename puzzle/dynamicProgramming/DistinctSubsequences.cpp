// Given a string S and a string T, count the number of distinct 
// subsequences of S which equals T.

// A subsequence of a string is a new string which is formed from 
// the original string by deleting some (can be none) of the 
// characters without disturbing the relative positions of the 
// remaining characters. (ie, "ACE" is a subsequence of "ABCDE" 
// while "AEC" is not).

// Example 1:

// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:

// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)

// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// Example 2:

// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:

// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)

// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

/* 感觉这种方法更好理解一些 */
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
            return 0;
        int lengthX = s.size(), lengthY = t.size();
        vector<vector<int>> vec(lengthX, vector<int>(lengthY, -1));
        return dfs(s, t, vec, lengthX - 1, lengthY - 1);
    }
private:
    int dfs(string& s, string& t, vector<vector<int>>& vec, int i, int j) {
        if (j == -1)
            return 1;
        if (i == -1)
            return 0;
        if (vec[i][j] == -1) {
            if (s[i] == t[j]) {
                vec[i][j] = dfs(s, t, vec, i - 1, j) + dfs(s, t, vec, i - 1, j - 1);
            } else {
                vec[i][j] = dfs(s, t, vec, i - 1, j);
            }
        }
        return vec[i][j];
    }
};

class Solution2 {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
            return 0;
        int lengthX = s.size(), lengthY = t.size();
        vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
        for (int i = 0; i <= lengthX; ++i)
            vec[i][0] = 1;
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                if (s[i - 1] == t[j - 1])
                    vec[i][j] = vec[i - 1][j] + vec[i - 1][j - 1];
                else
                    vec[i][j] = vec[i - 1][j];
            }
        }
        return vec[lengthX][lengthY];
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    REQUIRE(test.numDistinct("rabbbit", "rabbit") == 3);
    REQUIRE(test.numDistinct("geeksforgeeks", "ge") == 6);
}
