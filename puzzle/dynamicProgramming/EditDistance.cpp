// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int minDistance(string word1, string word2, int ic, int dc, int rc) {
        if (word1.empty())
            return ic * word2.size();
        if (word2.empty())
            return dc * word1.size();
        int lengthX = word1.size(), lengthY = word2.size();
        vector<vector<int>> vec(lengthX + 1, vector<int>(lengthY + 1));
        for (int i = 0; i <= lengthX; ++i)
            vec[i][0] = i * dc;
        for (int i = 0; i <= lengthY; ++i)
            vec[0][i] = i * ic;
        for (int i = 1; i <= lengthX; ++i) {
            for (int j = 1; j <= lengthY; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    vec[i][j] = vec[i - 1][j - 1];
                } else {
                    vec[i][j] = std::min({vec[i - 1][j] + dc, vec[i][j - 1] + ic, vec[i - 1][j - 1] + rc});
                }
            }
        }
        return vec[lengthX][lengthY];
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    REQUIRE(test.minDistance("abc", "adc", 5, 3 ,2) == 2);
    REQUIRE(test.minDistance("abc", "adc", 5, 3, 100) == 8);
    REQUIRE(test.minDistance("ab12cd3", "abcdf", 5, 3, 2) == 8);
}
