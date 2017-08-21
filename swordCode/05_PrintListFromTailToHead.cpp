/**
 *
 * 输入一个链表，从尾到头打印链表每个节点的值。
 *
 */

#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
};

/* 如果不能修改输入的话，就不能翻转链表 */
/*class Solution {
public:
  vector<int> printListFromTailToHead(ListNode *head) {
    if (head == nullptr)
      return {};
    stack<int> node;
    while(head) {
      node.push(head->val);
      head = head->next;
    }
    vector<int> result;
    while (!node.empty()) {
      result.push_back(node.top());
      node.pop();
    }
    return result;
  }
};*/

class Solution {
public:
  vector<int> printListFromTailToHead(ListNode *head) {
    vector<int> result;

    printFromTailToHead(head, result);

    return result;
  }

private:
  void printFromTailToHead(ListNode *head, vector<int>& result) {
    if (head == NULL)
      return;
    printFromTailToHead(head->next, result);
    result.push_back(head->val);
  }
};