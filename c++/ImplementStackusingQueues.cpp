/**
 *
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 *
 * Notes:
 * You must use only standard operations of a queue -- which means
 * only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively.
 * You may simulate a queue by using a list or deque (double-ended queue),
 * as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 *
 *
 */

#include <queue>

using std::queue;

class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack(): myQueue() {}

  /** Push element x onto stack. */
  void push(int x) {
    myQueue.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int element = myQueue.back();
    int size = myQueue.size();
    while (size > 1) {
      myQueue.push(myQueue.front());
      myQueue.pop();
      size--;
    }
    myQueue.pop();
    return element;
  }

  /** Get the top element. */
  int top() {
    return myQueue.back();
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return myQueue.empty();
  }

private:
  queue<int> myQueue;
};