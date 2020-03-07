// Given a linked list, return the node where the cycle begins. 
// If there is no cycle, return null.

// To represent a cycle in the given linked list, we use an integer 
// pos which represents the position (0-indexed) in the linked list 
// where tail connects to. If pos is -1, then there is no cycle in the linked list.

// Note: Do not modify the linked list.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *first = head, *second = head;
        bool cycle = false;
        while (first && first->next) {
            first = first->next->next;
            second= second->next;
            if (first == second) {
                cycle = true;
                break;
            }
        }
        if (cycle == false)
            return NULL;
        first = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};