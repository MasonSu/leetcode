// A message containing letters from A-Z is being encoded to numbers 
// using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total 
// number of ways to decode it.

// Example 1:

// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

// '0'需要特殊考虑
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        int length = s.size();
        vector<int> vec(length + 1);
        vec[0] = 1;
        vec[1] = 1;
        for (int i = 2; i <= length; ++i) {
            if (s[i - 1] != '0')
                vec[i] += vec[i - 1];
            if (s[i - 2] != '0') {
                int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (num >= 1 && num <= 26)
                    vec[i] += vec[i - 2];
            }
        }
        return vec[length];
    }
};