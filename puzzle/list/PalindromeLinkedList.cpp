// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode *first = head, *second = head;
        while (first->next && first->next->next) {
            first = first->next->next;
            second = second->next;
        }
        ListNode *head2 = second->next;
        head2 = reverse(head2);
        
        while (head2) {
            if (head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    
private:
    ListNode* reverse(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};