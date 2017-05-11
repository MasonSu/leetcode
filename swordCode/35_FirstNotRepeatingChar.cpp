/** 
 * 在一个字符串(1<=字符串长度<=10000，全部由字母组成)
 * 中找到第一个只出现一次的字符,并返回它的位置。如果字符串为空,返回-1
 */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
  int FirstNotRepeatingChar(string str) {
    if (str.empty())
      return -1;
    int hashTable[128] = {0};
    for (const char &c : str)
      hashTable[c]++;
    for (int i = 0; i < str.size(); ++i)
      if (hashTable[str[i]] == 1)
        return i;
    return -1;
  }
};