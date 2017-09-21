/**
 * Given an integer n, count the total number of digit 1
 * appearing in all non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */

/* Failed */
#include <iostream>

class Solution {
public:
  int countDigitOne(int n) {
    int count = 0;
    long long ten = 1;
    while (ten <= n) {
      int num1 = n % ten;
      int num2 = (n / ten) % 10;
      int num3 = (n / ten) / 10;

      if (num2 < 1) {
        count += num3 * ten;
      } else if (num2 == 1) {
        count += num3 * ten + 1 + num1;
      } else if (num2 > 1) {
        count += (num3 + 1) * ten;
      }

      ten *= 10;
    }

    return count;
  }
};