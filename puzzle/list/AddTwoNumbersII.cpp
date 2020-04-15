// You are given two non-empty linked lists representing two non-negative integers. The most 
// significant digit comes first and each of their nodes contain a single digit. Add the two 
// numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL)
            return l1 == NULL ? l2 : l1;
        l1 = reverse(l1), l2 = reverse(l2);
        ListNode *pre = new ListNode(0), *head = pre;
        int count = 0;
        while (l1 || l2 || count) {
            ListNode *node = new ListNode(count);
            if (l1) {
                node->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                node->val += l2->val;
                l2 = l2->next;
            }
            count = node->val / 10;
            node->val %= 10;
            head->next = node;
            head = head->next;
        }
        return reverse(pre->next);
    }
    
private:
    ListNode* reverse(ListNode* l) {
        ListNode *pre = NULL, *cur = l, *next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};