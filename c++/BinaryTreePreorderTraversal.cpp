/** 
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [1,2,3].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    preorder(root, result);
    return result;
  }

private:
  void preorder(TreeNode *root, vector<int>& vec) {
    if (root == NULL)
      return;
    vec.push_back(root->val);
    preorder(root->left, vec);
    preorder(root->right, vec);
  }
};*/

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == NULL)
      return {};
    vector<int> result;
    stack<TreeNode*> nodes;
    while (root || nodes.size()) {
      if (root) {
        result.push_back(root->val);
        nodes.push(root);
        root = root->left;
      } else {
        root = nodes.top();
        nodes.pop();
        root = root->right;
      }
    }
    return result;
  }
};