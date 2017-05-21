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

/*class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == NULL)
      return {};
    vector<vector<int>> result;
    vector<int> vec;
    queue<TreeNode*> nodes1, nodes2;
    nodes1.push(root);
    while (nodes1.size()) {
      root = nodes1.front();
      nodes1.pop();
      vec.push_back(root->val);
      if (root->left)
        nodes2.push(root->left);
      if (root->right)
        nodes2.push(root->right);
      if (nodes1.empty()) {
        result.push_back(vec);
        vec.clear();
        nodes1 = nodes2;
        nodes2 = queue<TreeNode*>();
      }
    }
    return result;
  }
};*/

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