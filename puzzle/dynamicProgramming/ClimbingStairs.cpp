// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct 
// ways can you climb to the top?

// Note: Given n will be a positive integer.

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        vector<int> vec(n + 1);
        vec[0] = 1;
        vec[1] = 1;
        for (int i = 2; i <= n; ++i)
            vec[i] = vec[i - 1] + vec[i - 2];
        return vec[n];
    }
};