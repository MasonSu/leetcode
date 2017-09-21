/**
 * 输入一棵二叉树，求该树的深度。从根结点到叶
 * 结点依次经过的结点（含根、叶结点）形成树的
 * 一条路径，最长路径的长度为树的深度。
 */

#include <iostream>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int TreeDepth(TreeNode* pRoot)
  {
    if (pRoot == NULL)
      return 0;
    int left = TreeDepth(pRoot->left) + 1;
    int right = TreeDepth(pRoot->right) + 1;
    return left > right ? left : right;
  }
};