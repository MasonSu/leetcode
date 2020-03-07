// Given a non-empty string s and a dictionary wordDict containing a list of non-empty 
// words, determine if s can be segmented into a space-separated sequence of one or more 
// dictionary words.

// Note:

// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:

// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        for (auto s : wordDict)
            us.insert(s);
        int length = s.size();
        vector<int> vec(length + 1);
        vec[0] = 1;
        for (int i = 1; i <= length; ++i) {
            for (int j = i; j <= length; ++j) {
                if (us.count(s.substr(i - 1, j - i + 1)) != 0 && vec[i - 1] == 1)
                    vec[j] = 1;
            }
            if (vec[length] == 1)
                return true;
        }
        return false;
    }
};