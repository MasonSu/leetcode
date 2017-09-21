/**
 * 输入两个链表，找出它们的第一个公共结点。
 */

#include <iostream>

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL || pHead2 == NULL)
      return NULL;

    ListNode *first = pHead1, *second = pHead2;
    while (first != second) {
      first = first == NULL ? pHead2 : first->next;
      second = second == NULL ? pHead1 : second->next;
    }

    return first;
  }
};