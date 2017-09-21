/**
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印
 */

#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> PrintFromTopToBottom(TreeNode* root) {
    if (root == NULL)
      return {};

    queue<TreeNode*> nodes;
    nodes.push(root);

    vector<int> result;

    while (nodes.size()) {
      TreeNode *node = nodes.front();
      nodes.pop();

      result.push_back(node->val);
      if (node->left)
        nodes.push(node->left);
      if (node->right)
        nodes.push(node->right);

    }

    return result;
  }
};