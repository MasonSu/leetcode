/** 
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along 
 * the shortest path from the root node down to the nearest leaf node.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    int leftDepth = minDepth(root->left) + 1;
    int rightDepth = minDepth(root->right) + 1;
    /* 
     * in case 
     *    1
     *   /
     *  2
     */
    if (leftDepth == 1 || rightDepth == 1)
      return leftDepth + rightDepth - 1;
    else
      return leftDepth < rightDepth ? leftDepth : rightDepth;
  }
};