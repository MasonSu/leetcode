// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> um;
        int start = 0, result = 0, count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (um[s[i]]++ == 1) {
                count = 1;
            }
            while (count) {
                if (um[s[start]]-- == 2) {
                    count = 0;
                }
                start++;
            }
            result = std::max(result, i - start + 1);
        }
        return result;
    }
};

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    Solution test;
    REQUIRE(test.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(test.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(test.lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(test.lengthOfLongestSubstring("abcbda") == 4);
    REQUIRE(test.lengthOfLongestSubstring("jfieioqp") == 5);
}
