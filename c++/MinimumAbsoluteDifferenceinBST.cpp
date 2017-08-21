/**
 * Given a binary search tree with non-negative values, find
 * the minimum absolute difference between values of any two nodes.
 *
 * Example:
 * Input:
 *
 *   1
 *    \
 *     3
 *    /
 *   2
 *
 * Output:
 * 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference
 * between 2 and 1 (or between 2 and 3).
 *
 * Note: There are at least two nodes in this BST.
 */

/* 一次遍历就够了 */
#include <iostream>
#include <stack>
#include <climits>

using std::stack;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    stack<TreeNode*> nodes;
    TreeNode *prev = NULL;
    int min = INT_MAX;
    while (root || nodes.size()) {
      if (root) {
        nodes.push(root);
        root = root->left;
      } else {
        TreeNode *node = nodes.top();
        nodes.pop();
        if (prev != NULL && node->val - prev->val < min)
          min = node->val - prev->val;
        prev = node;
        root = node->right;
      }
    }

    return min;
  }
};