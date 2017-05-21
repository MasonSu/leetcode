/** 
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined 
 * as a binary tree in which the depth of the two subtrees of 
 * every node never differ by more than 1.
 */

#include <iostream>
#include <cstdlib>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

/*class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == NULL)
      return true;
    if (std::abs(depth(root->left) - depth(root->right)) <= 1)
      return isBalanced(root->left) && isBalanced(root->right);
    else
      return false;
  }

private:
  int depth(TreeNode *root) {
    if (root == NULL)
      return 0;
    int leftDepth = depth(root->left) + 1;
    int rightDepth = depth(root->right) + 1;
    return leftDepth > rightDepth ? leftDepth : rightDepth;
  }
};*/

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    return depth(root) == -1 ? false : true;
  }

private:
  int depth(TreeNode *root) {
    if (root == NULL)
      return 0;
    int leftDepth = depth(root->left) + 1;
    if (leftDepth == 0)
      return -1;
    int rightDepth = depth(root->right) + 1;
    if (rightDepth == 0)
      return -1;
    if (std::abs(leftDepth - rightDepth) > 1)
      return -1;
    else
      return leftDepth > rightDepth ? leftDepth : rightDepth;
  }
};