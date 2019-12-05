// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// Example:

// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty())
            return {};
        vector<vector<string>> result;
        vector<string> vec;
        dfs(result, vec, s, 0);
        return result;
    }
private:
    void dfs(vector<vector<string>>& result, vector<string>& vec, string& s, int begin) {
        if (begin == s.size()) {
            result.push_back(vec);
            return;
        }
        for (int i = begin; i < s.size(); ++i) {
            if (palindrome(s, begin, i)) {
                vec.push_back(s.substr(begin, i - begin + 1));
                dfs(result, vec, s, i + 1);
                vec.pop_back();
            }
        }
    }

    bool palindrome(string& s, int begin, int end) {
        while (begin < end) {
            if (s[begin] != s[end])
                return false;
            begin++;
            end--;
        }
        return true;
    }
};