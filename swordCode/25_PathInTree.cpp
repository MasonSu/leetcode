/**
 * 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为
 * 输入整数的所有路径。路径定义为从树的根结点开始往下一
 * 直到叶结点所经过的结点形成一条路径。
 */

#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> FindPath(TreeNode *root, int exceptNumber) {
    if (root == NULL)
      return {};

    vector<vector<int>> result;
    vector<int> vec;

    path(root, exceptNumber, result, vec);

    return result;
  }

private:
  void path(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> &vec) {
    if (root == NULL)
      return;

    vec.push_back(root->val);
    if (root->val == sum && root->left == NULL && root->right == NULL)
      result.push_back(vec);

    path(root->left, sum - root->val, result, vec);
    path(root->right, sum - root->val, result, vec);

    vec.pop_back();
    return;
  }
};
