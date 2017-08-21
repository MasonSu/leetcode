/**
 * Follow up for problem "Populating Next Right Pointers
 * in Each Node".
 *
 * What if the given tree could be any binary tree? Would
 * your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 *
 * After calling your function, the tree should look like:
 *
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 */

#include <iostream>
#include <queue>

using std::queue;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (root == NULL)
      return;

    queue<TreeLinkNode*> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()) {
      int size = myQueue.size();
      TreeLinkNode *prev = NULL;
      for (int i = 0; i < size; ++i) {
        TreeLinkNode *node = myQueue.front();
        myQueue.pop();
        if (node->left)
          myQueue.push(node->left);
        if (node->right)
          myQueue.push(node->right);

        if (prev == NULL)
          prev = node;
        else {
          prev->next = node;
          prev = prev->next;
        }
      }
      prev->next = NULL;
    }
  }
};
