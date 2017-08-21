/**
 * Given the root of a tree, you are asked to find
 * the most frequent subtree sum. The subtree sum of
 * a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including
 * the node itself). So what is the most frequent subtree
 * sum value? If there is a tie, return all the values
 * with the highest frequency in any order.
 *
 * Examples 1
 * Input:
 *    5
 *   /  \
 *  2   -3
 *
 * return [2, -3, 4], since all the values happen only once,
 * return all of them in any order.
 *
 * Examples 2
 * Input:
 *   5
 *  /  \
 * 2   -5
 *
 * return [2], since 2 happens twice, however -5 only occur once.
 * Note: You may assume the sum of values in any subtree is in the
 * range of 32-bit signed integer.
 */

/* Failed */
#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> hashMap;

    subtreeSum(root, hashMap);

    vector<int> result;
    int max = 0;
    for (auto iter = hashMap.begin(); iter != hashMap.end(); ++iter) {
      if (iter->second > max) {
        max = iter->second;
        result.clear();
        result.push_back(iter->first);
      } else if (iter->second == max) {
        result.push_back(iter->first);
      }
    }

    return result;
  }

private:
  /* sum不能通过参数调用，必须通过返回值返回 */
  int subtreeSum(TreeNode *root, unordered_map<int, int>& hashMap) {
    if (root == NULL)
      return 0;

    int left = subtreeSum(root->left, hashMap);
    int right = subtreeSum(root->right, hashMap);

    int sum = root->val + left + right;
    hashMap[sum]++;

    return sum;
  }
};