// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

#define CATCH_CONFIG_MAIN
#include <bits/stdc++.h>

using namespace std;

#include "catch.hpp"

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
        	return "";
        std::unordered_map<char, int> target_count;
        for (auto &c : t) {
        	target_count[c]++;
        }
        int start = 0, end = 0, count = 0, result_start = -1, result_length = INT_MAX;
        while (end < s.size()) {
        	if (--target_count[s[end]] >= 0)
        		count++;
        	while (count == t.size()) {
        		if (end - start + 1 < result_length) {
        			result_start = start;
        			result_length = end - start + 1;
        		}
        		if (++target_count[s[start]] > 0) {
        			count--;
        		}
        		start++;
        	}
        	end++;
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