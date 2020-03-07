// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note:  

// 1 is typically treated as an ugly number.
// n does not exceed 1690.

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
        vector<int> vec(n);
        vec[0] = 1;
        int index1 = 0, index2 = 0, index3= 0;
        for (int i = 1; i < n; ++i) {
            int num1 = vec[index1] * 2;
            int num2 = vec[index2] * 3;
            int num3 = vec[index3] * 5;
            vec[i] = std::min({num1, num2, num3});
            if (vec[i] == num1)
                index1++;
            if (vec[i] == num2)
                index2++;
            if (vec[i] == num3)
                index3++;
        }
        return vec[n - 1];
    }
};