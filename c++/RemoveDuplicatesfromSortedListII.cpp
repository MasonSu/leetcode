/**
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
    bool duplicate = false;
    ListNode *pre = &dummyHead, *curr = head;
    while (curr->next != NULL) {
      if (curr->val == curr->next->val) {
        duplicate = true;
        curr->next = curr->next->next;
      } else {
        if (duplicate) {
          duplicate = false;
          pre->next = curr->next;
        } else {
          pre = curr;
        }
        curr = curr->next;
      }
    }
    /* Need to consider 1->1->1 */
    if (duplicate)
      pre->next = curr->next;
    return dummyHead.next;
  }
};