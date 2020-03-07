// Given n pairs of parentheses, write a function to 
// generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {};
        vector<string> result;
        string str;
        dfs(result, str, 0, 0, n);
        return result;
    }
    
private:
    void dfs(vector<string>& result, string str, int left, int right, int n) {
        if (left + right == 2 * n) {
            result.push_back(str);
            return;
        }
        if (left < n)
            dfs(result, str + "(", left + 1, right, n);
        if (right < left)
            dfs(result, str + ")", left, right + 1, n);
    }
};