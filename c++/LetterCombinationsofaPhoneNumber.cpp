/**
 *
 * Given a digit string, return all possible letter combinations that the number
 * could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/
 * 200px-Telephone-keypad2.svg.png
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */

/* Failed  */
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};   /* Empty vector */
    vector<string> vec {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result {""};   /* Not empty vector */
    for (int i = 0; i < digits.size(); ++i) {
      vector<string> tmp;         /* Empty vector */
      int num = digits[i] - '0';
      if (num < 0 || num > 9)
        continue;
      for (int j = 0; j < result.size(); ++j)
        for (int k = 0; k < vec[num].size(); ++k)
          tmp.push_back(result[j] + vec[num][k]);
      result.swap(tmp);  /* swap is more faster than assignment */
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  string digits("234");
  for (const string& str : test.letterCombinations(digits))
    std::cout << str << " ";
  std::cout << '\n';
  return 0;
}