/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * Example 1:
 *     2
 *    / \
 *   1   3
 * Binary tree [2,1,3], return true.
 * Example 2:
 *     1
 *    / \
 *   2   3
 * Binary tree [1,2,3], return false.
 */

#include <iostream>
#include <stack>

using std::stack;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

/* [10,5,15,null,null,6,20] */
/*class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (root == NULL)
      return true;

    if (root->left && root->right) {
      if (root->val > root->left->val && root->val < root->right->val)
        return isValidBST(root->left) && isValidBST(root->right);
      else
        return false;
    } else if (root->left == NULL && root->right == NULL)
      return true;
    else {
      if (root->left)
        return root->val > root->left->val && isValidBST(root->left);
      if (root->right)
        return root->val < root->right->val && isValidBST(root->right);
    }
  }
};*/

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (root == NULL)
      return true;

    stack<TreeNode*> myStack;
    TreeNode *pre = NULL;

    while (root || myStack.size()) {
      if (root) {
        myStack.push(root);
        root = root->left;
      } else {
        TreeNode *node = myStack.top();
        myStack.pop();
        if (pre != NULL && pre->val >= node->val)
          return false;
        pre = node;
        root = node->right;
      }
    }
    return true;
  }
};