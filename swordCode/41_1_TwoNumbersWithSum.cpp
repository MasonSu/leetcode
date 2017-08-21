/**
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
 * 是的他们的和正好是S，如果有多对数字的和等于S，输出两个
 * 数的乘积最小的。
 */

#include <iostream>
#include <vector>
#include <climits>

using std::vector;

class Solution {
public:
  vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    if (array.empty())
      return {};

    vector<int> result;
    int min = INT_MAX;
    for (int i = 0, j = array.size() - 1; i < j;) {
      if (array[i] + array[j] == sum) {
        if (array[i] * array[j] < min) {
          result.clear();
          result.push_back(array[i]);
          result.push_back(array[j]);
          i++, j--;
        } else if (array[i] + array[j] < sum)
          i++;
        else
          j--;
      }
    }

    return result;
  }
};