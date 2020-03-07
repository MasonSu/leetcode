// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {};
        unordered_map<string, vector<string>> um;
        for (auto &s : strs) {
            string t = s;
            std::sort(t.begin(), t.end());
            um[t].push_back(s);
        }
        vector<vector<string>> result;
        for (auto iter = um.begin(); iter != um.end(); ++iter) {
            result.push_back(iter->second);
        }
        return result;
    }
};