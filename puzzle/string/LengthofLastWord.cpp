// Given a string s consists of upper/lower-case alphabets and empty 
// space characters ' ', return the length of last word (last word 
// means the last appearing word if we loop from left to right) in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a maximal substring consisting of non-space 
// characters only.

// Example:

// Input: "Hello World"
// Output: 5

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        int second = s.size() - 1;
        while (second >= 0 && s[second] == ' ')
            second--;
        if (second < 0)
            return 0;
        int first = second;
        while (first >= 0 && s[first] != ' ')
            first--;
        return second - first;
    }
};