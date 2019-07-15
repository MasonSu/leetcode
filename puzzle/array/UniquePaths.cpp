#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = result[i - 1][j] + result[i][j - 1];
                }
            }
        }
        return result[m - 1][n - 1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        /* num取较小的数，减少循环次数，num1和num2变量类型设定为long long，防止溢出 */
        int total = m + n - 2, down = std::min(m - 1, n - 1), num = down;
        long long num1 = 1, num2 = 1;
        for (int i = 0; i < num; ++i) {
            num1 = num1 * (total--);
            num2 = num2 * (down--);
        }
        return num1 / num2;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution2 test;
    REQUIRE(test.uniquePaths(36,7) == 4496388);
}
