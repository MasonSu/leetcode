/**
 * Given preorder and inorder traversal of a tree,
 * construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

/*class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty())
      return NULL;

    TreeNode *root = new TreeNode(preorder[0]);
    auto iter = std::find(inorder.begin(), inorder.end(), root->val);
    vector<int> inLeft(inorder.begin(), iter), inRight(iter + 1, inorder.end());
    vector<int> preLeft(preorder.begin() + 1, preorder.begin() + 1 + inLeft.size()),
           preRight(preorder.begin() + 1 + inLeft.size(), preorder.end());

    root->left = buildTree(preLeft, inLeft);
    root->right = buildTree(preRight, inRight);

    return root;
  }
};*/

/* 省去了构造vector的时间 */
class Solution {
public:
  TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildCore(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }

private:
  TreeNode *buildCore(const vector<int>& preorder, const vector<int>& inorder,
                      int preStart, int preEnd, int inStart, int inEnd) {
    if (preEnd - preStart == 0 || inEnd - inStart == 0)
      return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);
    int pos = inStart;
    for (; pos < inEnd; ++pos)
      if (inorder[pos] == root->val)
        break;

    int length = pos - inStart;
    root->left = buildCore(preorder, inorder, preStart + 1, preStart + 1 + length,
                           inStart, inStart + length);
    root->right = buildCore(preorder, inorder, preStart + 1 + length, preEnd,
                            inStart + length + 1, inEnd);

    return root;
  }
};