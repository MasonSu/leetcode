// Find all possible combinations of k numbers that add up to a 
// number n, given that only numbers from 1 to 9 can be used and 
// each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> vec;
        dfs(result, vec, k, n, 1);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& result, vector<int>& vec, int k, int target, int begin) {
        if (target == 0 && vec.size() == k) {
            result.push_back(vec);
            return;
        }
        if (vec.size() == k)
            return;
        for (int i = begin; i < 10 && i <= target; ++i) {
            vec.push_back(i);
            dfs(result, vec, k, target - i, i + 1);
            vec.pop_back();
        }
    }
};