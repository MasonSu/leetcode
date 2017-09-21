/**
 * Given a binary tree, return the zigzag level order traversal
 * of its nodes' values. (ie, from left to right, then right to
 * left for the next level and alternate between).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == NULL)
      return {};
    vector<vector<int>> result;
    queue<TreeNode*> nodes;
    nodes.push(root);
    bool zigzag = true;
    while (nodes.size()) {
      int size = nodes.size();
      vector<int> vec(size);
      for (int i = 0; i < size; ++i) {
        TreeNode *root = nodes.front();
        nodes.pop();

        int index = zigzag ? i : size - 1 - i;
        vec[index] = root->val;

        if (root->left)
          nodes.push(root->left);
        if (root->right)
          nodes.push(root->right);
      }
      zigzag = !zigzag;
      result.push_back(vec);
    }
    return result;
  }
};