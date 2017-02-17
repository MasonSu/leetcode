/**
 *
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 * 
 * Note: Do not modify the linked list.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
  ListNode *detectCycle(ListNode *head) {
    if (head == NULL)
      return head;
    ListNode *fast = head, *slow = head;
    bool cycle = false;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        cycle = true;
        break;
      }
    }
    if (!cycle)
      return NULL;
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};