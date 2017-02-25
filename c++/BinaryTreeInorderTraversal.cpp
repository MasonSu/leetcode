/**
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 */

#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

/*class Solution {
public:
  void push(TreeNode* root, vector<int>& nums) {
    if (root == NULL)
      return;
    push(root->left, nums);
    nums.push_back(root->val);
    push(root->right, nums);
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    push(root, result);
    return result;
  }
};*/

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL)
      return {};
    stack<TreeNode*> nodes;
    vector<int> result;
    while (root || !nodes.empty()) {
      if (root) {
        nodes.push(root);
        root = root->left;
      } else {
        TreeNode *node = nodes.top();
        result.push_back(node->val);
        nodes.pop();
        root = node->right;
      }
    }
    return result;
  }
};