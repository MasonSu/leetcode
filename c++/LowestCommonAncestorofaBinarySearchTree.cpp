/**
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) 
 * of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor 
 * is defined between two nodes v and w as the lowest node in T that has both v 
 * and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *       _______6______
 *      /              \
 *   ___2__          ___8__
 *  /      \        /      \
 *  0      _4       7       9
 *        /  \
 *        3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 
 * and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
 * since a node can be a descendant of itself according to the LCA definition.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

/*class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL)
      return NULL;
    vector<TreeNode*> parent;
    findParent(root, p, parent);
    for (auto iter = parent.rbegin(); iter != parent.rend(); ++iter) {
      if (searchNode(*iter, q->val))
        return *iter;
    }
    return NULL;
  }

private:
  void findParent(TreeNode *root, TreeNode *node, vector<TreeNode*> &vec) {
    if (root == NULL)
      return;
    vec.push_back(root);
    if (node->val < root->val)
      findParent(root->left, node, vec);
    else if (node->val > root->val)
      findParent(root->right, node, vec);
  }

  bool searchNode(TreeNode *node, int val) {
    if (node == NULL)
      return false;
    if (val < node->val)
      return searchNode(node->left, val);
    else if (val > node->val)
      return searchNode(node->right, val);
    else
      return true;
  }
};*/

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL)
      return NULL;
    if (root->val > p->val && root->val > q->val)
      return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};