// Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", 
// so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

// Now we have another string p. Your job is to find out how many unique non-empty substrings of 
// p are present in s. In particular, your input is the string p and you need to output the number 
// of different non-empty substrings of p in the string s.

// Note: p consists of only lowercase English letters and the size of p might be over 10000.

// Example 1:
// Input: "a"
// Output: 1
// Explanation: Only the substring "a" of string "a" is in the string s.

// Example 2:
// Input: "cac"
// Output: 2
// Explanation: There are two substrings "a", "c" of string "cac" in the string s.

// Example 3:
// Input: "zab"
// Output: 6
// Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.

// https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/95439/Concise-Java-solution-using-DP
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.empty())
            return 0;
        // 记录以a~z结尾的连续字符串最长长度，这样可以有效去重
        unordered_map<char, int> um;
        int current_length = 0;
        for (int i = 0; i < p.size(); ++i) {
        	// 以当前字符结尾的最长长度
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25)) {
                current_length++;
            } else {
                current_length = 1;
            }
            um[p[i]] = std::max(um[p[i]], current_length);
        }
        int result = 0;
        for (auto iter = um.begin(); iter != um.end(); ++iter) {
            result += iter->second;
        }
        return result;
    }
};