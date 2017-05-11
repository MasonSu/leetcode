/** 
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 * 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student."，
 * 则输出"student. a am I"。
 */

#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;

/*class Solution {
public:
  string ReverseSentence(string str) {
    if (str.empty())
      return "";
    stack<string> strStack;
    string word;
    for (const char &c : str) {
      if (c != ' ')
        word += c;
      else {
        strStack.push(word);
        word.clear();
      }
    }
    string result = word;
    while (strStack.size()) {
      result += ' ' + strStack.top();
      strStack.pop();
    }
    return result;
  }
};*/

class Solution {
public:
  string ReverseSentence(string str) {
    if (str.empty())
      return "";
    reverseWord(str.begin(), str.end() - 1);

    string::iterator iter = str.begin();
    while (1) {
      string::iterator tmp = iter;
      do {
        ++iter;
      } while (*iter != ' ' && *iter != '\0');
      reverseWord(tmp, iter - 1);
      if (*iter == '\0')
        break;
      ++iter;
    }
    return str;
  }

private:
  void reverseWord(string::iterator begin, string::iterator end) {
    while (begin < end) {
      char c = *begin;
      *begin++ = *end;
      *end-- = c;
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  std::cout << test.ReverseSentence("I am a student.") << '\n';
  return 0;
}