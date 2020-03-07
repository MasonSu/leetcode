// Given a sorted linked list, delete all duplicates 
// such that each element appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *first = head, *second = head->next;
        while (second) {
            if (first->val == second->val) {
                second = second->next;
                first->next = second;
            } else {
                second = second->next;
                first = first->next;
            }
        }
        return head;
    }
};