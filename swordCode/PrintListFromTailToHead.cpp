/**
 *
 * 输入一个链表，从尾到头打印链表每个节点的值。
 *
 */


#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
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
};