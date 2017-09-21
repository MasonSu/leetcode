/** 
 * Given a binary tree, return the bottom-up level order traversal 
 * of its nodes' values. (ie, from left to right, level by level 
 * from leaf to root).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its bottom-up level order traversal as:
 *
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 */

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>

using std::vector;
using std::queue;
using std::deque;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (root == NULL)
      return {};
    deque<vector<int>> myDeque;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (nodes.size()) {
      vector<int> vec;
      int size = nodes.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *root = nodes.front();
        nodes.pop();
        vec.push_back(root->val);
        if (root->left)
          nodes.push(root->left);
        if (root->right)
          nodes.push(root->right);
      }
      myDeque.push_front(vec);
    }
    vector<vector<int>> result(make_move_iterator(myDeque.begin()), make_move_iterator(myDeque.end()));
    return result;
  }
};