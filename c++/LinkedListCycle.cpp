/**
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 */

/* Failed */
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

/* 1,2,3,4,2,3,4... */
/*class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *move = head;
    while (move && move->next) {
      if (move->next == head)
        return true;
      move = move->next;
    }
    return false;
  }
};*/

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == NULL)
      return false;
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
        return true;
    }
    return false;
  }
};