/**
 * 输入两个单调递增的链表，输出两个链表合成后的链表，
 * 当然我们需要合成后的链表满足单调不减规则。
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    ListNode dummyHead(0);
    ListNode *head = &dummyHead;
    while (pHead1 && pHead2) {
      if (pHead1->val < pHead2->val) {
        head->next = pHead1;
        pHead1 = pHead1->next;
      } else {
        head->next = pHead2;
        pHead2 = pHead2->next;
      }
      head = head->next;
    }
    head->next =  pHead1 ? pHead1 : pHead2;
    return dummyHead.next;
  }
};