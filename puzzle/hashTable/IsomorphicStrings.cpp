// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while 
// preserving the order of characters. No two characters may map to the same 
// character but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> um;
        unordered_set<char> us;
        for (int i = 0; i < s.size(); ++i) {
            if (um.count(s[i]) == 0) {
            	// 如果s[i]不存在，那么t[i]应该也没有被绑定过
                if (us.count(t[i]) != 0)
                    return false;
                us.insert(t[i]);
                um[s[i]] = t[i];
            } else {
                if (um[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};