/**
 *
 * Given a linked list and a value x, partition it such that all nodes 
 * less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each 
 * of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
  ListNode* partition(ListNode* head, int x) {
    if (head == NULL)
      return head;
    ListNode less(0), greater(0);
    ListNode *first = &less, *second = &greater;
    for (ListNode *curr = head; curr != NULL; curr = curr->next) {
      if (curr->val < x) {
        first->next = curr;
        first = first->next;
      } else {
        second->next = curr;
        second = second->next;
      }
    }
    second->next = NULL;        // important! avoid cycle in linked list
    first->next = greater.next;
    return less.next;
  }
};

int main(int argc, char const *argv[])
{
  ListNode t1(5), t2(6), t3(1), t4(2);
  t1.next = &t2;
  t2.next = &t3;
  t3.next = &t4;
  Solution test;
  ListNode *result = test.partition(&t1, 3);
  int count = 12;       
  /* if without second->next = NULL, result is 1,2,5,6,1,2,5,6,1,2,5,6... */
  for (; result && count > 0; result = result->next, --count)
    std::cout << result->val << " ";
  std::cout << '\n';
  return 0;
}