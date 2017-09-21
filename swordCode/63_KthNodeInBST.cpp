/**
 * 给定一颗二叉搜索树，请找出其中的第k大的结点。
 * 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数
 * 值大小顺序第三个结点的值为4。
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

/* 注意k的取值范围 */
class Solution {
public:
  TreeNode* KthNode(TreeNode* pRoot, int k)
  {
    if (pRoot == NULL || k <= 0)
      return NULL;

    stack<TreeNode*> nodes;
    int count = 0;
    while (pRoot || nodes.size()) {
      if (pRoot) {
        nodes.push(pRoot);
        pRoot = pRoot->left;
      } else {
        TreeNode *node = nodes.top();
        nodes.pop();
        count++;
        if (count == k)
          return node;
        pRoot = node->right;
      }
    }

    return NULL;
  }
};