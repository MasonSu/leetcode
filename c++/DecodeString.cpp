/**
 * Given an encoded string, return it's decoded string.
 *
 * The encoding rule is: k[encoded_string], where the
 * encoded_string inside the square brackets is being
 * repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid;
 * No extra white spaces, square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does
 * not contain any digits and that digits are only for those
 * repeat numbers, k. For example, there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

#include <string>
#include <stack>
#include <iostream>

using std::string;
using std::stack;

/*class Solution {
public:
  string decodeString(string s) {
    string result, str;
    stack<char> myStack;

    for (auto c : s) {
      if (c != ']')
        myStack.push(c);
      else {
        string tmpStr;
        while (myStack.top() != '[') {
          tmpStr = myStack.top() + tmpStr;
          myStack.pop();
        }
        myStack.pop();

        while (myStack.size() && myStack.top() - '0' >= 0 && myStack.top() - '0' <= 9) {
          str = myStack.top() + str;
          myStack.pop();
        }

        int num = std::stoi(str);
        str.clear();

        while (num--)
          str += tmpStr;

        if (myStack.empty())
          result += str;
        else {
          for (auto tc : str)
            myStack.push(tc);
        }
      }
    }

    str.clear();
    while (myStack.size()) {
      str = myStack.top() + str;
      myStack.pop();
    }

    return result + str;
  }
};*/

class Solution {
public:
  string decodeString(string s) {
    stack<int> intStack;
    stack<string> strStack;
    string str;
    int num = 0;

    for (auto c : s) {
      if (c - '0' >= 0 && c - '0' <= 9)
        num = num * 10 + c - '0';
      else if (c == '[') {
        intStack.push(num);
        num = 0;
        strStack.push(str);
        str.clear();
      } else if (c == ']') {
        string tmpStr = str;
        str = strStack.top();
        strStack.pop();
        num = intStack.top();
        intStack.pop();
        while (num) {
          str += tmpStr;
          num--;
        }
      } else
        str += c;
    }

    return str;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.decodeString("3[a]2[bc]") << '\n';
  return 0;
}