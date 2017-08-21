/**
 * Given a binary tree and a sum, find all root-to-leaf paths
 * where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \    / \
 *       7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (root == NULL)
      return {};
    vector<vector<int>> result;
    vector<int> vec;
    findPath(root, sum, result, vec);
    return result;
  }

private:
  void findPath(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> &vec) {
    if (root == NULL)
      return;
    vec.push_back(root->val);
    /* 就算找到满足条件的情况，最后插入的节点还是要弹出 */
    if (root->left == NULL && root->right == NULL && root->val == sum)
      result.push_back(vec);

    findPath(root->left, sum - root->val, result, vec);
    findPath(root->right, sum - root->val, result, vec);
    vec.pop_back();
  }
};