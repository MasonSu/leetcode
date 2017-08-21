/**
 * 小明很喜欢数学,有一天他在做数学作业时,要求计算出
 * 9~16的和,他马上就写出了正确答案是100。但是他并不
 * 满足于此,他在想究竟有多少种连续的正数序列的和为
 * 100(至少包括两个数)。没多久,他就得到另一组连续正
 * 数和为100的序列:18,19,20,21,22。现在把问题交给你,
 * 你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> FindContinuousSequence(int sum) {
    int start = 1, end = 2;
    int val = start + end;
    vector<vector<int>> result;

    while (start < end && end <= (sum + 1) / 2) {
      if (val == sum) {
        vector<int> vec;
        for (int i = start; i <= end; ++i)
          vec.push_back(i);
        result.push_back(vec);

        val -= start++;
      } else if (val > sum)
        val -= start++;
      else
        val += ++end;
    }

    return result;
  }
};