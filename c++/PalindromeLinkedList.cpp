/**
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == NULL)
      return true;

    ListNode *first = head, *second = head;

    while (second->next && second->next->next) {
      first = first->next;
      second = second->next->next;
    }

    first = first->next;
    first = reverse(first);

    while (first) {
      if (head->val != first->val)
        return false;
      head = head->next;
      first = first->next;
    }

    return true;
  }

private:
  ListNode *reverse(ListNode *head) {
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

int main(int argc, char const *argv[]) {
  Solution test;
  ListNode node1(1), node2(2), node3(2), node4(1);
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  test.isPalindrome(&node1);
  return 0;
}