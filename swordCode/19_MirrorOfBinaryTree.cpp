/** 
 * 操作给定的二叉树，将其变换为源二叉树的镜像。 
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
  void Mirror(TreeNode *pRoot) {
    if (pRoot == NULL)
      return;
    TreeNode *tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
  }
};