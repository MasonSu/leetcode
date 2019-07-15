#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int lengthX = matrix.size(), lengthY = matrix[0].size(), max = 0;
        vector<vector<int>> vec(lengthX, vector<int>(lengthY, 0));
        for (int i = 0; i < lengthX; ++i) {
            for (int j = 0; j < lengthY; ++j) {
                if (i == 0 || j == 0) {
                     vec[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    vec[i][j] = std::min({vec[i - 1][j - 1], vec[i - 1][j], vec[i][j - 1]}) + 1;
                }
                max = std::max(max, vec[i][j]);
            }
        }
        return max * max;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    vector<vector<char>> v1{{'1','0','1','0','0'},
                            {'1','0','1','1','1'},
                            {'1','1','1','1','1'},
                            {'1','0','0','1','0'}};
    REQUIRE(test.maximalSquare(v1) == 4);
    vector<vector<char>> v2{{'1'}};
    REQUIRE(test.maximalSquare(v2) == 1);
}
