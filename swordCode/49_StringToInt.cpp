/**
 * 将一个字符串转换成一个整数，要求不能使用字符串
 * 转换整数的库函数。 数值为0或者字符串不是一个
 * 合法的数值则返回0
 */

#include <string>
#include <climits>

using std::string;

class Solution {
public:
  int StrToInt(string str) {
    if (str.empty())
      return 0;

    int index = 0;
    while (str[index] == ' ')
      index++;

    int mul = 1;
    if (str[index] == '+' || str[index] == '-')
      mul = str[index++] == '-' ? -1 : 1;

    long long result = 0;
    while (index < str.size() && str[index] - '0' >= 0 && str[index] - '0' <= 9) {
      result = result * 10 + mul * (str[index] - '0');
      if (result < INT_MIN)
        return INT_MIN;
      else if (result > INT_MAX)
        return INT_MAX;

      index++;
    }

    if (index != str.size())
      return 0;
    else
      return result;
  }
};