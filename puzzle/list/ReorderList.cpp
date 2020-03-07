// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, 
// only nodes itself may be changed.

// Example 1:

// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

// 整个操作分为3步
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;
        // 找到中间节点
        ListNode *first = head, *second = head;
        while (first->next && first->next->next) {
            first = first->next->next;
            second = second->next;
        }
        ListNode *second_head = second->next;
        second->next = NULL;
        
        // 反转第二个链表
        ListNode *pre = NULL, *cur = second_head, *next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        second_head = pre;
        
        // 合并
        pre = new ListNode(0), cur = pre;
        while (head || second_head) {
            if (head) {
                cur->next = head;
                head = head->next;
                cur = cur->next;
            }
            if (second_head) {
                cur->next = second_head;
                second_head = second_head->next;
                cur = cur->next;
            }
        }
        head = pre->next;
    }
};