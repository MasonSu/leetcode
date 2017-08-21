/**
 * 输入一个链表，输出该链表中倒数第k个结点
 */

#include <iostream>

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == NULL)
      return NULL;

    ListNode *first = pListHead, *second = pListHead;
    for (int i = 0; i < k; ++i) {
      if (first == NULL)
        return NULL;
      first = first->next;
    }

    while (first) {
      first = first->next;
      second = second->next;
    }

    return second;
  }
};