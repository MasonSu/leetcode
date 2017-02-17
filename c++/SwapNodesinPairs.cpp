/**
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
 *
 */

/* Failed */
#include <iostream>

using std::cout;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode *pre = &dummyHead, *curr = head;
    while (curr && curr->next) {
      /* The order is very important */
      pre->next = curr->next;
      curr->next = curr->next->next;
      pre->next->next = curr;
      pre = curr;
      curr = curr->next;
    }
    return dummyHead.next;
  }
};

int main(int argc, char const *argv[])
{
  ListNode n1(1), n2(2);
  n1.next = &n2;
  Solution test;
  ListNode *result = test.swapPairs(&n1);
  for (ListNode *ptr = result; ptr != NULL; ptr = ptr->next)
    cout << ptr->val << ' ';
  cout << '\n'; 
  return 0;
}