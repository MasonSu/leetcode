/**
 *
 * Given a sorted linked list, delete all duplicates such that each element appear 
 * only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 */

#include <iostream>

using std::cout;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL)
      return head;
    ListNode dummyHead(0);
    dummyHead.next = head;
    for (ListNode *ptr = head; ptr->next != NULL;) {
      if (ptr->val == ptr->next->val)
        ptr->next = ptr->next->next;
      else
        ptr = ptr->next;
    }
    return dummyHead.next;
  }
};