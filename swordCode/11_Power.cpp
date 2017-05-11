/** 
 * 给定一个double类型的浮点数base和int类型的整数exponent。
 * 求base的exponent次方。
 *
 */

#include <iostream>

class Solution {
public:
  double Power(double base, int exponent) {
    if (exponent == 0)
      return 1;
    bool negative = false;
    if (exponent < 0) {
      negative = true;
      exponent *= -1;
    }
    int result = 1;
    while (exponent > 0) {
      result *= base;
      exponent--;
    }
    /* 记得将整数转换成浮点数，否则结果会是0 */
    return negative ? 1.0 / result : result;
  }
};