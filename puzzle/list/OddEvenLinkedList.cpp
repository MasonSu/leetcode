// Given a singly linked list, group all odd nodes together followed 
// by the even nodes. Please note here we are talking about the node
// number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) 
// space complexity and O(nodes) time complexity.

// Example 1:

// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL
// Example 2:

// Input: 2->1->3->5->6->4->7->NULL
// Output: 2->3->6->7->1->5->4->NULL
// Note:

// The relative order inside both the even and odd groups should remain 
// as it was in the input.
// The first node is considered odd, the second node even and so on ...

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *pre1 = new ListNode(0), *pre2 = new ListNode(0);
        ListNode *head1 = pre1, *head2 = pre2;
        bool odd = true;
        while (head) {
            if (odd) {
                head1->next = head;
                head1 = head1->next;
            } else {
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
            odd = !odd;
        }
        head1->next = pre2->next;
        head2->next = NULL;
        return pre1->next;
    }
};