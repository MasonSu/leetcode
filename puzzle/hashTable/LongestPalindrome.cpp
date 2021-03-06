// Given a string which consists of lowercase or uppercase letters, find the 
// length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> um;
        int count = 0;
        for (char c : s) {
            um[c]++;
            if (um[c] == 2) {
                count += 2;
                um.erase(c);
            }
        }
        if (um.size())
            count++;
        return count;
    }
};