/** 
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:        a1 → a2
 *                  ↘
 *                    c1 → c2 → c3
 *                  ↗            
 * B:   b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 */

/* Failed */
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL)
      return NULL;

    ListNode *nodeA = headA, *nodeB = headB;
    /* If one of them reaches the end earlier then reuse it
     * by moving it to the beginning of other list. Once both
     * of them go through reassigning, they will be equidistant
     */
    while (nodeA != nodeB) {
      nodeA = nodeA != NULL ? nodeA->next : headB;
      nodeB = nodeB != NULL ? nodeB->next : headA;
    }

    return nodeA;
  }
};