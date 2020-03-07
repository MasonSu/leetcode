// Merge k sorted linked lists and return it as one sorted list. 
// Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

// O(nk Logk)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        
        auto comp = [](ListNode *a, ListNode *b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pg(comp);

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL)
                pg.push(lists[i]);
        }

        ListNode *pre = new ListNode(0), *head = pre;
        while (pg.size()) {
            ListNode *node = pg.top();
            pg.pop();

            if (node->next)
                pg.push(node->next);

            head->next = node;
            head = head->next;
        }
        
        return pre->next;
    }
};

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        	return NULL;
        int start = 0, end = lists.size() - 1;
        while (end != 0) {
        	start = 0;
        	while(start < end) {
	        	lists[start] = mergeTwoLists(lists[start], lists[end]);
	        	start++;
	        	end--;
	        }
        }
        return lists[0];
    }

 private:
 	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
 		if (l1 == NULL || l2 == NULL)
 			return l1 ? l1 : l2;
 		ListNode *pre = new ListNode(0), *head = pre;
 		while (l1 && l2) {
 			if (l1->val < l2->val) {
 				head->next = l1;
 				l1 = l1->next;
 			} else {
 				head->next = l2;
 				l2 = l2->next;
 			}
 			head = head->next;
 		}
 		head->next = l1 ? l1 : l2;
 		return pre->next;
 	}
};
