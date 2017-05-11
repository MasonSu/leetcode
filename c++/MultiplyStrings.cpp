/**
 * Given two non-negative integers num1 and num2 represented
 * as strings, return the product of num1 and num2.
 *
 * Note:
 *
 *     1. The length of both num1 and num2 is < 110.
 *     2. Both num1 and num2 contains only digits 0-9.
 *     3. Both num1 and num2 does not contain any leading zero.
 *     4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

/* Failed */
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Solution {
public:
  /* 使用整形的话会溢出，使用double不会溢出，但是精度没
     办法保证，double的精度算上小数点之前之后，总共有15位 */
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    int length1 = num1.size(), length2 = num2.size();
    vector<int> vec(length1 + length2);
    for (int i = length1 - 1; i >= 0; --i)
      for (int j = length2 - 1; j >= 0; --j)
        vec[i + j +1] += (num1[i] - '0') * (num2[j] - '0');
    string result;
    int div = 0;
    for (int i = length1 + length2 - 1; i > 0; --i) {
      result = char('0' + (vec[i] + div) % 10) + result;
      div = (vec[i] + div) / 10;
    }
    if (div != 0)
      result = char('0' + div) + result;
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  cout << test.multiply("98", "76") << '\n';
  return 0;
}