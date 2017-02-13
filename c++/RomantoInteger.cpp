/**
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */


#include <string>
#include <unordered_map>
#include <iostream>

using std::string;
using std::unordered_map;

class Solution {
public:
  int romanToInt(string s) {
    if (s.empty())
      return 0;
    unordered_map<char, int> romanNumeral = 
    {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000},
    };
    int sum = 0;
    for (auto iter = s.begin(); iter != s.end() - 1; ++iter) {
      if (romanNumeral[*iter] >= romanNumeral[*(iter+1)])
        sum += romanNumeral[*iter];
      else
        sum -= romanNumeral[*iter];
    }
    sum += romanNumeral[s.back()];
    return sum;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  string str("MMXIV");
  std::cout << test.romanToInt(str) << std::endl;
  return 0;
}