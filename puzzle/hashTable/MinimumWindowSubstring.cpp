// Given a string S and a string T, find the minimum window in S 
// which will contain all the characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, 
// return the empty string "".
// If there is such window, you are guaranteed that there will always 
// be only one unique minimum window in S.

#define CATCH_CONFIG_MAIN
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        int count = 0;
        unordered_map<char, int> um;
        for (auto c : t) {
            um[c]++;
            count++;
        }
        int result_length = INT_MAX, result_start = 0;
        int first = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (um[s[i]]-- > 0)
                count--;
            while (count == 0) {
                if (i - first + 1 < result_length) {
                    result_length = i - first + 1;
                    result_start = first;
                }
                if (++um[s[first]] > 0)
                    count++;
                first++;
            }
        }
        if (result_length == INT_MAX)
            return "";
        return s.substr(result_start, result_length);
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    std::string s = "ADOBECODEBANC", t = "ABC";
    REQUIRE(test.minWindow(s, t) == "BANC");
}