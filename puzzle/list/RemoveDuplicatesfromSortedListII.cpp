// Given a sorted linked list, delete all nodes that have duplicate 
// numbers, leaving only distinct numbers from the original list.

// Example 1:

// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
// Example 2:

// Input: 1->1->1->2->3
// Output: 2->3

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *pre = new ListNode(0), *cur = pre;
        ListNode *first = head;
        while (first) {
            bool flag = false;
            ListNode *second = first->next;
            while (second && first->val == second->val) {
                flag = true;
                second = second->next;
            }
            // flag为true表明first也需要删除
            if (flag == false) {
                cur->next = first;
                cur = cur->next;
            }
            first = second;
        }
        // 这一步很关键	
        cur->next = NULL;
        return pre->next;
    }
};