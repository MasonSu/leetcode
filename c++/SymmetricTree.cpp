/**
 *
 * Given a binary tree, check whether it is a mirror of
 * itself (ie, symmetric around its center).
 *
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
  bool isSubSymmetric(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL || t2 == NULL)
      return t1 == t2;
    if (t1->val == t2->val)
      return isSubSymmetric(t1->left, t2->right) && isSubSymmetric(t1->right, t2->left);
    else
      return false;
  }

  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true;
    return isSubSymmetric(root->left, root->right);
  }
};