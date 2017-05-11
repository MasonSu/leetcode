/** 
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */

#include <iostream>

class Solution {
public:
  int NumberOf1(int n) {
    int count = 0;
    /* 需要循环32次 */
    for (int i = 0; i < sizeof(int) * 8; ++i) {
      if (n & 1)
        count++;
      n = n >> 1;
    }
    return count;
  }
};

/*class Solution {
public:
  int NumberOf1(int n) {
    int count = 0;
    while (n) {
      count++;
      n = n & (n - 1);
    }
    return count;
  }
};*/

