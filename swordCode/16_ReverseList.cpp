/** 
 * 输入一个链表，反转链表后，输出链表的所有元素。
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *ReverseList(ListNode *pHead) {
    if (pHead == NULL)
      return NULL;
    ListNode dummyHead(0);
    dummyHead.next = pHead;
    ListNode *node = pHead->next;
    pHead->next = NULL;
    while (node) {
      ListNode *tmp = node->next;
      node->next = dummyHead.next;
      dummyHead.next = node;
      node = tmp;
    }
    return dummyHead.next;
  }
};