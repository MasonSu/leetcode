// Given a linked list, reverse the nodes of a linked list k at 
// a time and return its modified list.

// k is a positive integer and is less than or equal to the length 
// of the linked list. If the number of nodes is not a multiple of 
// k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes 
// itself may be changed.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode *pre = new ListNode(0), *cur = pre;
        while (1) {
            vector<ListNode*> result = reverseK(head, k);
            cur->next = result[0];
            head = result[1];
            if (head == NULL)
                break;
            int t = k;
            while (t) {
                cur = cur->next;
                t--;
            }
        }
        return pre->next;
    }
    
private:
    vector<ListNode*> reverseK(ListNode* head, int k) {
        vector<ListNode*> result;
        stack<ListNode*> st;
        ListNode *origin = head;
        while (k) {
            if (head == NULL) {
                result.push_back(origin);
                result.push_back(NULL);
                return result;
            }
            st.push(head);
            head = head->next;
            k--;
        }
        ListNode *top = st.top();
        st.pop();
        ListNode *next = top->next, *origin_top = top;
        while (st.size()) {
            top->next = st.top();
            st.pop();
            top = top->next;
        }
        top->next = NULL;
        result.push_back(origin_top);
        result.push_back(next);
        return result;
    }
};