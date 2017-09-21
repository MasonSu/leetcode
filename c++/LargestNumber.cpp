/**
 * Given a list of non negative integers, arrange
 * them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the
 * largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need
 * to return a string instead of an integer.
 */

/* Failed */
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    if (nums.empty())
      return "";

    vector<string> str;
    str.reserve(nums.size());

    for (auto i : nums)
      str.push_back(std::to_string(i));

    std::sort(str.begin(), str.end(), [](string a, string b) {return a + b > b + a;});

    string result;
    for (auto s : str)
      result += s;

    /* [0,0,0] */
    if (result == string(result.size(), '0'))
      return "0";

    return result;
  }
};