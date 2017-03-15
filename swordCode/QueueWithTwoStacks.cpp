/**
 *
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 
 * 队列中的元素为int类型。
 *
 */


#include <stack>
#include <stdexcept>

using std::stack;

class Solution {
public:
  void push(int node) {
    stack1.push(node);
  }

  int pop() {
    if (stack2.empty()) {
      if (stack1.empty())
        throw std::runtime_error("queue is empty");
      while (stack1.size()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    int node = stack2.top();
    stack2.pop();
    return node;
  }

private:
  stack<int> stack1;
  stack<int> stack2;
};