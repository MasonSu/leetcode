/**
 * 求出1~13的整数中1出现的次数,并算出100~1300的
 * 整数中1出现的次数？为此他特别数了一下1~13中
 * 包含1的数字有1、10、11、12、13因此共出现6次,
 * 但是对于后面问题他就没辙了。ACMer希望你们帮
 * 帮他,并把问题更加普遍化,可以很快的求出任意非
 * 负整数区间中1出现的次数。
 */

#include <iostream>

class Solution {
public:
  int NumberOf1Between1AndN_Solution(int n) {
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