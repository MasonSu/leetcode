// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes 
// of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL)
            return l1 ? l1 : l2;
        ListNode *pre = new ListNode(0);
        ListNode *head = pre;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = l1 ? l1 : l2;
        return pre->next;
    }
};