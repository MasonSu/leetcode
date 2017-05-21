/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  /* 因为不用修改头指针，所以不需要返回头指针，如果头指针改变的话，必须返回头指针 */
  void reorderList(ListNode *head) {
    if (head == NULL)
      return;
    ListNode dummyHead(0);
    dummyHead.next = head;
    /* 将链表分为前后两个部分 */
    ListNode *firstHead = head, *secondHead = head->next;
    while (secondHead && secondHead->next) {
      firstHead = firstHead->next;
      secondHead = secondHead->next->next;
    }
    secondHead = firstHead->next;
    firstHead->next = NULL;
    firstHead = dummyHead.next;
    /* 翻转第二个链表 */
    secondHead = reverseList(secondHead);
    /* 合并两个链表 */
    head = &dummyHead;
    bool flag = true;
    while (firstHead || secondHead) {
      if (flag) {
        head->next = firstHead;
        firstHead = firstHead->next;
      } else {
        head->next = secondHead;
        secondHead = secondHead->next;
      }
      head = head->next;
      flag = !flag;
    }
  }

private:
  ListNode* reverseList(ListNode *head) {
    if (head == NULL)
      return head;
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode *node = head->next;
    head->next = NULL;
    while (node) {
      ListNode *tmp = node->next;
      node->next = dummyHead.next;
      dummyHead.next = node;
      node = tmp;
    }
    return dummyHead.next;
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  ListNode *n1 = new ListNode(1), *n2 = new ListNode(2), *n3 = new ListNode(3), *n4 = new ListNode(4);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  test.reorderList(n1);
  while (n1) {
    std::cout << n1->val << ' ';
    n1 = n1->next;
  }
  std::cout << '\n';
  return 0;
}