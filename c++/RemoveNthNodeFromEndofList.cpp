/**
 *
 * Given a linked list, remove the nth node from the end of list
 * and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 *
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL)
      return head;
    int length = 1;
    for (ListNode* ptr = head; ptr->next != NULL; ptr = ptr->next)
      length++;
    if (length == n)
      return head->next;
    int k = 0;
    for (ListNode* ptr = head; ptr->next != NULL; ptr = ptr->next) {
      if (k == length - n - 1) {
        ptr->next = ptr->next->next;
        break;
      }
      k++;
    }
    return head;
  }
};*/

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL)
      return head;
    ListNode* first = head;
    for (int i = 0; i < n; ++i)
      first = first->next;
    if (first == NULL)
      return head->next;
    ListNode* second = head;
    while (first->next != NULL) {
      first = first->next;
      second = second->next;
    }
    second->next = second->next->next;
    return head;
  }
};