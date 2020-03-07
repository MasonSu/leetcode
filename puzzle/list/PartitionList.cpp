// Given a linked list and a value x, partition it such that 
// all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each 
// of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return NULL;
        ListNode *pre_first = new ListNode(0), *pre_second = new ListNode(0);
        ListNode *first = pre_first, *second = pre_second;
        while (head) {
            if (head->val < x) {
                first->next = head;
                first = first->next;
            } else {
                second->next = head;
                second = second->next;
            }
            head = head->next;
        }
        second->next = NULL;
        first->next = pre_second->next;
        return pre_first->next;
    }
};