/**
 * 一个整型数组里除了两个数字之外，其他的数字
 * 都出现了两次。请写程序找出这两个只出现一次的数字。
 */

#include <vector>

using std::vector;

class Solution {
public:
  void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
    int result = 0;
    for (auto i : data)
      result ^= i;

    int num = result & (~(result - 1));

    *num1 = 0, *num2 = 0;
    for (auto i : data) {
      if (i & num)
        *num1 ^= i;
      else
        *num2 ^= i;
    }
  }
};