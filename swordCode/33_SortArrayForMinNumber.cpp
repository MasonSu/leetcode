/**
 * 输入一个正整数数组，把数组里所有数字拼接起
 * 来排成一个数，打印能拼接出的所有数字中最小
 * 的一个。例如输入数组{3，32，321}，则打印出
 * 这三个数字能排成的最小数字为321323。
 */

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
  string PrintMinNumber(vector<int> numbers) {
    if (numbers.empty())
      return "";

    vector<string> str;
    str.reserve(numbers.size());

    for (auto c : numbers)
      str.push_back(std::to_string(c));

    std::sort(str.begin(), str.end(), [](string a, string b) {return a + b < b + a;});

    string result;
    for (auto s : str)
      result += s;

    return result;
  }
};