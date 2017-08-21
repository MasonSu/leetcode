/**
 *
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
 * 则重建二叉树并返回。
 *
 */


#include <vector>
#include <algorithm>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    if (pre.empty() || vin.empty())
      return nullptr;
    TreeNode *root = new TreeNode(pre[0]);
    if (pre.size() == 1 || vin.size() == 1)
      return root;
    
    auto iter = std::find(vin.begin(), vin.end(), pre[0]);
    vector<int> vinLeft(vin.begin(), iter), vinRight(iter + 1, vin.end());
    auto middle = pre.begin() + 1 + vinLeft.size();
    vector<int> preLeft(pre.begin() + 1, middle), preRight(middle, pre.end());
    root->left = reConstructBinaryTree(preLeft, vinLeft);
    root->right = reConstructBinaryTree(preRight, vinRight);
    return root;
  }
};