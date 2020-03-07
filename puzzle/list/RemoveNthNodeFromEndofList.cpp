// Given a linked list, remove the n-th node from the end of 
// list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list 
// becomes 1->2->3->5.
// Note:

// Given n will always be valid.

// Follow up:

// Could you do this in one pass?

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        ListNode *first = head, *second = head;
        while (n) {
            first = first->next;
            n--;
        }
        // 特殊处理，删除的是head
        if (first == NULL) {
            return head->next;
        }
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return head;
    }
};