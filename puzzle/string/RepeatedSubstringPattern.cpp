// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

//  

// Example 1:

// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
// Example 2:

// Input: "aba"
// Output: False
// Example 3:

// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty())
            return true;
        for (int i = 1; i <= s.size() / 2; ++i) {
            string str = s.substr(0, i);
            if (s.size() % str.size())
                continue;
            int j;
            for (j = i; j < s.size(); j += str.size())
                if (str != s.substr(j, str.size()))
                    break;
            if (j == s.size())
                return true;
        }
        return false;
    }
};

/* O(n) */
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty())
            return true;
        for (int i = 1; i <= s.size() / 2; ++i) {
            string str = s.substr(0, i);
            if (s.size() % str.size())
                continue;

            string leftShift = s.substr(i) + str;
            if (leftShift == s)
                return true;
        }
        return false;
    }
};