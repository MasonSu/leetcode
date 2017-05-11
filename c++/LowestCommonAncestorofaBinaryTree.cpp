/** 
 * Given a binary tree, find the lowest common ancestor (LCA) 
 * of two given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common 
 * ancestor is defined between two nodes v and w as the lowest node in 
 * T that has both v and w as descendants (where we allow a node to be 
 * a descendant of itself).”
 *
 *       _______3______
 *      /              \
 *   ___5__          ___1__
 *  /      \        /      \
 *  6      _2       0       8
 *        /  \
 *        7   4
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
 * Another example is LCA of nodes 5 and 4 is 5, since a node can be a 
 * descendant of itself according to the LCA definition.
 */

/* Failed */
#include <iostream>
#include <vector>

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
    vector<vector<TreeNode*>> result;
    vector<TreeNode*> vec;
    findPath(root, p, result, vec);
    if (!result.empty())
      vec = result.front();
    for (auto iter = vec.rbegin(); iter != vec.rend(); ++iter)
      if (findNum(*iter, q->val))
        return *iter;
    return NULL;
  }

private:
  void findPath(TreeNode *root, TreeNode *node, vector<vector<TreeNode*>> &result, vector<TreeNode*> &vec) {
    if (root == NULL)
      return;
    vec.push_back(root);
    if (node->val == root->val) {
      result.push_back(vec);
      vec.pop_back();
      return;
    }
    findPath(root->left, node, result, vec);
    findPath(root->right, node, result, vec);
    vec.pop_back();
  }

  bool findNum(TreeNode *root, int val) {
    if (root == NULL)
      return false;
    if (root->val == val)
      return true;
    else
      return findNum(root->left, val) || findNum(root->right, val);
  }
};*/

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL || root == p || root == q)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)
      return root;
    return left != NULL ? left : right;
  }
};