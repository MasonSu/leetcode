// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively 
// or recursively. Could you implement both?

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        stack<ListNode*> st;
        while (head) {
            st.push(head);
            head = head->next;
        }
        ListNode *pre = new ListNode(0), *cur = pre;
        while (st.size()) {
            cur->next = st.top();
            st.pop();
            cur = cur->next;
        }
        cur->next = NULL;
        return pre->next;
    }
};	

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        	return NULL;
        ListNode *prev = NULL, *cur = head, *next = NULL;
        while (cur) {
        	next = cur->next;
        	cur->next = prev;
        	prev = cur;
        	cur = next;
        }
        return prev;
    }
};