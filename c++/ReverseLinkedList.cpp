/** 
 * Reverse a singly linked list.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode dummyHead(0);

    while (head) {
      ListNode *node = head->next;
      head->next = dummyHead.next;
      dummyHead.next = head;
      head = node;
    }

    return dummyHead.next;
  }
};