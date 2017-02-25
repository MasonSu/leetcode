/**
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *
 * return its level order traversal as:
 *
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == NULL)
      return {};
    vector<vector<int>> result;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
      vector<int> level;
      int size = nodes.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = nodes.front();
        nodes.pop();
        level.push_back(node->val);
        if (node->left)
          nodes.push(node->left);
        if (node->right)
          nodes.push(node->right);
      }
      result.push_back(level);
    }
    return result;
  }
};