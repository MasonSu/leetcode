#include <iostream>
#include <vector>
#include <tuple>

using std::cout;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
  TreeNode* buildBST(TreeNode *node, vector<int>& nums);
  TreeNode* lookup(TreeNode *node, int target);
  TreeNode* insert(TreeNode *node, int value);
  TreeNode* deleteNode(TreeNode *node, int value);
  int size(TreeNode *node);
  int maxDepth(TreeNode *node);
  int minValue(TreeNode *node);
  int maxValue(TreeNode *node);
  void printPreOrder(TreeNode *node);
  void printInOrder(TreeNode *node);
  void printPostOrder(TreeNode *node);

  void printPaths(TreeNode *node);
  TreeNode* mirror(TreeNode *node);
  TreeNode* doubleTree(TreeNode *node);
  bool sameTree(TreeNode *t1, TreeNode *t2);
  int countTree(int numKeys);
  bool isBST(TreeNode *node);

private:

};

TreeNode* BinaryTree::buildBST(TreeNode *node, vector<int>& nums) {
  for (int i : nums)
    node = insert(node, i);
  return node;
}

TreeNode* BinaryTree::lookup(TreeNode *node, int target) {
  if (node == NULL)
    return NULL;
  if (node->val == target)
    return node;
  else if (node->val < target)
    return lookup(node->right, target);
  else
    return lookup(node->left, target);
}

TreeNode* BinaryTree::insert(TreeNode *node, int value) {
  if (node == NULL) {
    TreeNode *tnode = new TreeNode(value);
    return tnode;
  }
  if (node->val < value)
    node->right = insert(node->right, value);
  else if (node->val > value)
    node->left = insert(node->left, value);
  return node;
}

TreeNode* BinaryTree::deleteNode(TreeNode *node, int value) {
  if (node == NULL) {
    cout << "Not found" << '\n';
    return node;
  }
  if (node->val < value)
    node->right = deleteNode(node->right, value);
  else if (node->val > value)
    node->left = deleteNode(node->left, value);
  else {
    if (node->left == NULL && node->right == NULL) {
      delete node;
      node = NULL;
      return node;
    } else if (node->left == NULL && node->right != NULL) {
      TreeNode *right = node->right;
      delete node;
      return right;
    } else if (node->left != NULL && node->right == NULL) {
      TreeNode *left = node->left;
      delete node;
      return left;
    } else {
      int lmax = maxValue(node->left);
      node->val = lmax;
      node->left = deleteNode(node->left, lmax);
      return node;
    }
  }
  return node;
}

int BinaryTree::size(TreeNode *node) {
  if (node == NULL)
    return 0;
  return size(node->left) + 1 + size(node->right);
}

int BinaryTree::maxDepth(TreeNode *node) {
  if (node == NULL)
    return -1;
  int ldepth = maxDepth(node->left) + 1;
  int rdepth = maxDepth(node->right) + 1;
  return ldepth > rdepth ? ldepth : rdepth;
}

int BinaryTree::minValue(TreeNode *node) {
  if (node == NULL)
    return -1;
  while (node->left)
    node = node->left;
  return node->val;
}

int BinaryTree::maxValue(TreeNode *node) {
  if (node == NULL)
    return -1;
  while (node->right)
    node = node->right;
  return node->val;
}

void BinaryTree::printPreOrder(TreeNode *node) {
  if (node == NULL)
    return;
  cout << node->val << ' ';
  printPreOrder(node->left);
  printPreOrder(node->right);
}

void BinaryTree::printInOrder(TreeNode *node) {
  if (node == NULL)
    return;
  printInOrder(node->left);
  cout << node->val << ' ';
  printInOrder(node->right);
}

void BinaryTree::printPostOrder(TreeNode *node) {
  if (node == NULL)
    return;
  printPostOrder(node->left);
  printPostOrder(node->right);
  cout << node->val << ' ';
}

TreeNode* BinaryTree::mirror(TreeNode *node) {
  if (node == NULL)
    return node;
  TreeNode *tmpNode = node->left;
  node->left = node->right;
  node->right = tmpNode;

  node->left = mirror(node->left);
  node->right = mirror(node->right);
  return node;
}

TreeNode* BinaryTree::doubleTree(TreeNode *node) {
  if (node == NULL)
    return node;
  TreeNode *tmpNode = node->left;
  node->left = new TreeNode(node->val);
  node->left->left = tmpNode;

  node->left->left = doubleTree(node->left->left);
  node->right = doubleTree(node->right);
  return node;
}

bool BinaryTree::sameTree(TreeNode *t1, TreeNode *t2) {
  if (t1 == NULL && t2 == NULL)
    return true;
  else if (t1 == NULL && t2 != NULL)
    return false;
  else if (t1 != NULL && t2 == NULL)
    return false;
  else {
    if (t1->val == t2->val)
      return sameTree(t1->left, t2->left) && sameTree(t1->right, t2->right);
    else
      return false;
  }
}

int main(int argc, char const *argv[])
{
  BinaryTree bst;
  TreeNode *root1 = NULL, *root2 = NULL;
  vector<int> nums1 {2, 1, 3}, nums2 {2, 3, 1};
  root1 = bst.buildBST(root1, nums1);
  root2 = bst.buildBST(root2, nums2);
  cout << bst.sameTree(root1, root2);
  //bst.printPreOrder(root);
  cout << '\n';
  return 0;
}