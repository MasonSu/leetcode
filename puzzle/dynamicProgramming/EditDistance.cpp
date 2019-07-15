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
