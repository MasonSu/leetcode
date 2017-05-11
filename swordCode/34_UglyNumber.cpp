/** 
 * 把只包含素因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含因子7。 
 * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
  int GetUglyNumber(int index) {
    if (index <= 0)
      return 0;
    vector<int> vec{1};
    int index2 = 0, index3 = 0, index5 = 0, count = 1;
    while (count < index) {
      int value = std::min({vec[index2] * 2, vec[index3] * 3, vec[index5] * 5});
      if (value == vec[index2] * 2)
        index2++;
      if (value == vec[index3] * 3)
        index3++;
      if (value == vec[index5] * 5)
        index5++;
      vec.push_back(value);
      count++;
    }
    return vec.back();
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.GetUglyNumber(150) << '\n';
  return 0;
}