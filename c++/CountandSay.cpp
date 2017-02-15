/**
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 *
 */

#include <string>
#include <iostream>

using std::string;
using std::cout;

/* beginning number is n */
/*class Solution {
public:
  string countAndSay(int n) {
    string num = std::to_string(n);
    for (int i = 0; i < n; ++i) {
      string result;
      for (auto iter = num.begin(); iter != num.end();) {
        int count = 1;
        for (auto tmp = iter; *tmp == *(tmp+1); ++tmp)
          count++;
        result = result + std::to_string(count) + *(iter);
        iter += count;
      }
      num = result;
    }
    return num;
  }
};*/

class Solution {
public:
  string countAndSay(int n) {
    string result("1");
    for (int i = 1; i < n; ++i) {     
      string num;
      for (auto iter = result.begin(); iter != result.end(); ) {
        int count = 1;
        for (auto tmp = iter; *(tmp) == *(tmp+1); ++tmp)
          count++;
        num = num + std::to_string(count) + *(iter);
        iter += count;       
      }
      result = num;
    }
    return result;
  }
};


int main(int argc, char const *argv[])
{
  Solution test;
  cout << test.countAndSay(3) << '\n';
  return 0;
}