// Write a program to find the node at which the intersection 
// of two singly linked lists begins.

// 如果不相交，最后会同时指向NULL
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *l1 = headA, *l2 = headB;
        while (l1 != l2) {
            l1 = (l1 == NULL ? headB : l1->next);
            l2 = (l2 == NULL ? headA : l2->next);
        }
        return l1;
    }
};