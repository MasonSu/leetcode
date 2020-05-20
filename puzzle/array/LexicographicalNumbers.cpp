// Given an integer n, return 1 - n in lexicographical order.

// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

// Please optimize your algorithm to use less time and space. The 
// input size may be as large as 5,000,000.

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; ++i) {
            dfs(i, n, result);
        }
        return result;
    }

private:
    void dfs(int current, int n, vector<int>& result) {
        if (current > n)
            return;
        result.push_back(current);
        // 小于等于这个条件看似有些多余，是为了早点结束循环
        for (int i = 0; i < 10 && current * 10 + i <= n; ++i) {
            dfs(current * 10 + i, n, result);
        }
    }
};