// Given a string s, you are allowed to convert it to a palindrome by 
// adding characters in front of it. Find and return the shortest 
// palindrome you can find by performing this transformation.

// Example 1:

// Input: "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: "abcd"
// Output: "dcbabcd"

// O(N^2) 找到从开头开始的最长palindrome string
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return "";
        string str;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (isPalindrome(s, 0, i)) {
                str = s.substr(i + 1);
                break;
            }
        }
        std::reverse(str.begin(), str.end());
        return str + s;
    }
    
private:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};