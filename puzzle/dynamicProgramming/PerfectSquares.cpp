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