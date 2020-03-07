// Implement strStr().

// Return the index of the first occurrence of needle in 
// haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        // 这里需要提前判断，否则两者相减如果为负，会变成一个非常大的正数
        if (haystack.size() < needle.size())
            return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            if (haystack[i] == needle[0]) {
                if (same(haystack, i, needle))
                    return i;
            }
        }
        return -1;
    }

private:
    bool same(const string& s1, int index, const string& s2) {
        for (int i = 0; i < s2.size(); ++i) {
            if (s1[index + i] != s2[i])
                return false;
        }
        return true;
    }
};