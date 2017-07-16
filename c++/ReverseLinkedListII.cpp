/** 
 * Reverse a linked list from position m to n. Do it 
 * in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ? m ? n ? length of list.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode *curNode = &dummyHead, *firstSaveNode, *secondSaveNode;

    while (m > 1) {
      curNode = curNode->next;
      m--;
      n--;
    } 

    firstSaveNode = curNode;
    secondSaveNode = curNode->next;
    curNode = curNode->next;

    ListNode tmpHead(0);
    while (n >= m) {
      ListNode *node = curNode->next;
      curNode->next = tmpHead.next;
      tmpHead.next = curNode;
      curNode = node;
      m++;
    }

    firstSaveNode->next = tmpHead.next;
    secondSaveNode->next = curNode;

    return dummyHead.next;
  }
};