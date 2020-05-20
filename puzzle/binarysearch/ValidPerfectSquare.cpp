// Given a positive integer num, write a function which returns 
// True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Output: true
// Example 2:

// Input: 14
// Output: false

class Solution {
public:
    bool isPerfectSquare(int num) {
        long start = 0, end = num;
        while (start < end) {
            long middle = start + (end - start) / 2;
            if (middle * middle < num) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        return end * end == num;
    }
};