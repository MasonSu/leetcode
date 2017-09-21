/**
 * 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否为该栈的弹出顺序。假设压
 * 入栈的所有数字均不相等。例如序列1,2,3,4,5是某
 * 栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的
 * 一个弹出序列，但4,3,5,1,2就不可能是该压栈序列
 * 的弹出序列。（注意：这两个序列的长度是相等的）
 */

#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::vector;
using std::stack;

/*class Solution {
public:
  bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.empty() || popV.empty())
      return true;

    int target = popV[0], index = -1;
    for (int i = 0; i < pushV.size(); ++i) {
      if (pushV[i] == target) {
        index = i;
        break;
      }
    }

    if (index == -1)
      return false;

    int first = index - 1, second = index + 1;

    for (int i = 1; i < popV.size(); ) {
      if (first >= 0 && popV[i] == pushV[first]) {
        first--;
        i++;
      }
      else {
        if (second == popV.size())
          return false;

        if (popV[i] == pushV[second]) {
          second++;
          i++;
        }
        else {
          pushV[++first] = pushV[second++];
        }
      }
    }

    return true;
  }
};*/

/*class Solution {
public:
  bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.empty() || popV.empty())
      return true;

    stack<int> myStack;

    for (int i = 0, j = 0; i < popV.size() && j <= pushV.size(); ) {
      if (!myStack.empty() && myStack.top() == popV[i]) {
        myStack.pop();
        i++;
      } else {
        if (j == pushV.size())
          return false;

        if (popV[i] == pushV[j]) {
          i++;
          j++;
        } else {
          myStack.push(pushV[j]);
          j++;
        }
      }
    }

    return true;
  }
};*/

class Solution {
public:
  bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.empty() || popV.empty())
      return true;

    stack<int> myStack;

    for (int i = 0, j = 0; i < pushV.size(); ++i) {
      myStack.push(pushV[i]);
      while (j < popV.size() && !myStack.empty() && myStack.top() == popV[j]) {
        myStack.pop();
        j++;
      }
    }

    return myStack.empty();
  }
};