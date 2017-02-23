/**
 *
 * Sort a linked list using insertion sort.
 *
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

/*class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummyHead(0);
    ListNode *pre = &dummyHead, *ptr = head;
    while (ptr) {
      ListNode *save = ptr->next;
      while (pre->next && ptr->val > pre->next->val)
        pre = pre->next;
      ptr->next = pre->next;
      pre->next = ptr;
      pre = &dummyHead;
      ptr = save;
    }
    return dummyHead.next;
  }
};*/

class Solution {
public:
  ListNode* sort(ListNode *left, ListNode *right) {
    ListNode dummyHead(0);
    ListNode *head = &dummyHead;
    while (left && right) {
      if (left->val < right->val) {
        head->next = left;
        left = left->next;
      } else {
        head->next = right;
        right = right->next;
      }
      head = head->next;
    }
    head->next = left ? left : right;
    return dummyHead.next;
  }

  int length(ListNode *head) {
    int count = 0;
    while (head) {
      count++;
      head = head->next;
    }
    return count;
  }

  ListNode* insertionSortList(ListNode* head) {
    int size = length(head);
    int middle = size / 2;
    if (middle == 0)
      return head;
    ListNode *left = head;
    for (int i = 1; i < middle; ++i)
      left = left->next;
    ListNode *right = left->next;
    left->next = NULL;
    left = insertionSortList(head);
    right = insertionSortList(right);
    return sort(left, right);
  }
};

int main(int argc, char const *argv[])
{
  Solution test;
  ListNode n1(1), n2(3), n3(2);
  n1.next = &n2;
  n2.next = &n3;
  ListNode *head = test.insertionSortList(&n1);
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << '\n';
  return 0;
}