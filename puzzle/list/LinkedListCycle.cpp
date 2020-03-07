// Given a linked list, determine if it has a cycle in it.

// To represent a cycle in the given linked list, we use an 
// integer pos which represents the position (0-indexed) in 
// the linked list where tail connects to. If pos is -1, then 
// there is no cycle in the linked list.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *first = head, *second = head;
        while (first && first->next) {
            first = first->next->next;
            second = second->next;
            if (first == second)
                return true;
        }
        return false;
    }
};