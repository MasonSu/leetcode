// Given a positive integer n, find the least number of perfect 
//  square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

/* 将一个数分解为完全平方数之和，求需要的最少的数的个数 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> vec(n + 1, INT_MAX);
        vec[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j)
                vec[i] = std::min(vec[i], vec[i - j * j] + 1);
        }
        return vec[n];
    }
};

/* 静态变量 */
class Solution2 {
public:
    int numSquares(int n) {
        static vector<int> vec{0};
        while (vec.size() <= n) {
            int target = vec.size(), value = INT_MAX;
            for (int i = 1; i * i <= target; ++i)
                value = std::min(value, vec[target - i * i] + 1);
            vec.push_back(value);
        }
        return vec[n];
    }
};