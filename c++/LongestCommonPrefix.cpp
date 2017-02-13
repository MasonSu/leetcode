/**
 *
 * Write a function to find the longest common prefix string 
 * amongst an array of strings.
 *
 */

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

// class Solution {
// public:
//   string longestCommonPrefix(vector<string>& strs) {
//     if (strs.empty())
//       return "";
//     if (strs.size() == 1)
//       return strs[0];
//     string first = strs[0], second = strs[1];
//     int length = first.size() <= second.size() ? first.size() : second.size();
//     string target;
//     for (int i = 0; i < length; ++i) {
//       if (first[i] == second[i])
//         target += first[i];
//       else {
//         if (i == 0)
//           return "";
//         break;
//       }
//     }
//     if (strs.size() == 2)
//       return target;
//     else {
//       for (int i = 2; i < strs.size(); ++i) {
//         /* Empty string */
//         if (strs[i].empty())
//           return "";
//         length = target.size() <= strs[i].size() ? target.size() : strs[i].size();
//         string tmptarget;
//         for (int j = 0; j < length; ++j) {
//           if (target[j] == strs[i][j])
//             tmptarget += target[j];
//           else {
//             if (j == 0)
//               return "";
//             break;
//           }
//         }
//         target = tmptarget;
//       }
//       return target;
//     }
//   }
// };

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
      return "";
    string pre = strs[0];
    for (int i = 1; i < strs.size(); ++i)
      while (strs[i].find(pre) != 0)
        pre = pre.substr(0, pre.size() - 1);
    return pre;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  vector<string> strs {"ac","ac","a","b"};
  std::cout << test.longestCommonPrefix(strs) << std::endl;
  return 0;
}