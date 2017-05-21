/**
 * Implement pow(x, n)
 */

#include <iostream>
#include <climits>

/*class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    long long num = n;
    if (num < 0) {
      x = 1 / x;
      num = -num;
    }
    return (num % 2) ? x * myPow(x * x, num / 2) : myPow(x * x, num / 2);
  }
};*/

class Solution {
public:
  double myPow(double x, int n) {
    /* in case n = INT_MIN */
    long long num = n;
    if (num < 0) {
      x = 1 / x;
      num = -num;
    }
    /* (int)(1.4 * 1.4) = 1 */
    double result = 1.0;
    while (num > 0) {
      if (num & 1)
        result *= x;
      num /= 2;
      x *= x;
    }
    return result;
  }
};