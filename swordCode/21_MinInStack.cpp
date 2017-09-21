/**
 * 定义栈的数据结构，请在该类型中实现一个能够
 * 得到栈最小元素的min函数。
 */

#include <iostream>
#include <stack>

using std::stack;

class Solution {
public:
  void push(int value) {
    stack1.push(value);
    if (stack2.empty() || value <= min())
      stack2.push(value);
  }
  void pop() {
    if (top() == stack2.top())
      stack2.pop();
    stack1.pop();
  }
  int top() {
    return stack1.top();
  }
  int min() {
    return stack2.top();
  }

private:
  stack<int> stack1;
  stack<int> stack2;
};