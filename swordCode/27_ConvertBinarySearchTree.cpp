/**
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序
 * 的双向链表。要求不能创建任何新的结点，只能调整树
 * 中结点指针的指向。
 */

#include <iostream>
#include <stack>

using std::stack;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* Convert(TreeNode* pRootOfTree)
  {
    if (pRootOfTree == NULL)
      return NULL;

    TreeNode *pre = NULL, *root = pRootOfTree;
    stack<TreeNode*> nodes;
    while (pRootOfTree || nodes.size()) {
      if (pRootOfTree) {
        nodes.push(pRootOfTree);
        pRootOfTree = pRootOfTree->left;
      } else {
        TreeNode *node = nodes.top();
        nodes.pop();
        if (pre == NULL)
          pre = node;
        else {
          pre->right = node;
          node->left = pre;
          pre = node;
        }

        pRootOfTree = node->right;
      }
    }

    while (root->left)
      root = root->left;

    return root;
  }
};