// Given a string, find the first non-repeating character in it and 
// return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

// 遍历两遍string
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty())
            return -1;
        unordered_map<char, int> um;
        for (auto c : s)
            um[c]++;
        for (int i = 0; i < s.size(); ++i) {
            if (um[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

// 遍历一遍string，遍历一遍map
class Solution2 {
public:
    int firstUniqChar(string s) {
        if (s.empty())
            return -1;
        unordered_map<char, int> um;
        for (int i = 0; i < s.size(); ++i) {
            if (um.count(s[i]) == 0) {
                um[s[i]] = i;
            } else {
                um[s[i]] = INT_MAX;
            }
        }
        int result = INT_MAX;
        for (auto iter = um.begin(); iter != um.end(); ++iter)
            result = std::min(result, iter->second);
        return result == INT_MAX ? -1 : result;
    }
};