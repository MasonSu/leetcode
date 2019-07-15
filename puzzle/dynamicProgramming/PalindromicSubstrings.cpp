#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty())
            return 0;
        int count = s.size(), low = 0, high = 0, length = s.size();
        for (int i = 1; i < length; ++i) {
            low = i - 1;
            high = i;
            while (low >= 0 && high < length && s[low] == s[high]) {
                low--;
                high++;
                count++;
            }
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < length && s[low] == s[high]) {
                low--;
                high++;
                count++;
            }
        }
        return count;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    REQUIRE(test.countSubstrings("abc") == 3);
    REQUIRE(test.countSubstrings("aaa") == 6);
}
