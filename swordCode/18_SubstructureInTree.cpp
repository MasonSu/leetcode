/**
 * 输入两棵二叉树A，B，判断B是不是A的子结构。
 * （ps：我们约定空树不是任意一个树的子结构）
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
  bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (pRoot1 == NULL || pRoot2 == NULL)
      return false;
    if (isSame(pRoot1, pRoot2))
      return true;
    else
      return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
  }

private:
  bool isSame(TreeNode *t1, TreeNode *t2) {
    /*if (t2 == NULL)
      return true;
    if (t1 == NULL)
      return false;*/
    if (t1 == NULL || t2 == NULL)
      return t1 == t2;
    if (t1->val == t2->val)
      return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
    else
      return false;
  }
};