/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，
 * 请你输出斐波那契数列的第n项。n<=39
 */

#include <iostream>

/* 不需要vector, 只需要保存最近的两个变量就行了 */
class Solution {
public:
  int Fibonacci(int n) {
    if (n <= 1)
      return n;

    int first = 0, second = 1;
    for (int i = 2; i <= n; ++i) {
      int third = first + second;
      first = second;
      second = third;
    }

    return second;
  }
};