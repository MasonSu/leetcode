// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

private:
    ListNode *mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *first = head, *second = head;
        while (first->next && first->next->next) {
            first = first->next->next;
            second = second->next;
        }
        ListNode *left = head, *right = second->next;
        second->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
    
    ListNode *merge(ListNode* l1, ListNode* l2) {
        ListNode *pre = new ListNode(0), *cur = pre;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return pre->next;
    }
};