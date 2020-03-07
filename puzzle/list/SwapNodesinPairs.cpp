// Given a linked list, swap every two adjacent nodes
// and return its head.

// You may not modify the values in the list's nodes, 
// only nodes itself may be changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *pre = new ListNode(0), *cur = pre;
        while (head && head->next) {
            ListNode *next = head->next->next;
            cur->next = head->next;
            head->next->next = head;
            cur = head;
            head = next;
        }
        // 这步很关键
        cur->next = head;
        return pre->next;
    }
};