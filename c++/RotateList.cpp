/** 
 * Given a list, rotate the list to the right by k places, 
 * where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL)
      return head;

    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode *first = head, *second = head;

    int length = 0;
    while (head) {
      length++;
      head = head->next;
    }
    /* [1, 2] 3 [2, 1] */
    k %= length;
    if (k == 0)
      return dummyHead.next;

    for (int i = 0; i < k; ++i)
      first = first->next;

    while (first->next) {
      first = first->next;
      second = second->next;
    }

    first->next = dummyHead.next;
    dummyHead.next = second->next;
    second->next = NULL;

    return dummyHead.next;
  }
};