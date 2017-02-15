/**
 *
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes
 * of the first two lists.
 *
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummyHead(0);
    ListNode *head = &dummyHead, *first = l1, *second = l2;
    while (first && second) {
      if (first->val <= second->val) {
        head->next = first;
        first = first->next;
      } else {
        head->next = second;
        second = second->next;
      }
      head = head->next;
    }
    head->next = first ? first : second;
    return dummyHead.next;
  }
};