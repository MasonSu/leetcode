/**
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single
 * digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode *l2) {
    ListNode dummyHead(0);
    ListNode* head = &dummyHead;
    int ten = 0;
    while (l1 || l2 || ten) {
      int sum = ten;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      ten = sum / 10;
      head->next = new ListNode(sum % 10);
      head = head->next;
    }
    return dummyHead.next;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  ListNode t1(9), t2(9);
  ListNode *node = test.addTwoNumbers(&t1, &t2);
  while (node) {
    std::cout << node->val << ' ';
    node = node->next;
  }
  std::cout << '\n';
  return 0;
}