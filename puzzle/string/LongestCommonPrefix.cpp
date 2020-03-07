// Write a function to find the longest common prefix string 
// amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        for (int index = 0; index < strs[0].size(); index++) {
            for (int i = 1; i < strs.size(); ++i) {
                if (index >= strs[i].size() || strs[0][index] != strs[i][index]) {
                    return strs[0].substr(0, index);
                }             
            }
        }
        return strs[0];
    }
};