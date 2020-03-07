// Given a linked list, rotate the list to the right by k places, 
// where k is non-negative.

// Example 1:

// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL

// Example 2:

// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode *cur = head;
        int length = 1;
        while (cur->next) {
            cur = cur->next;
            length++;
        }
        // 首尾相连
        cur->next = head;
        k = length - k % length;
        while (k) {
            cur = cur->next;
            k--;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};