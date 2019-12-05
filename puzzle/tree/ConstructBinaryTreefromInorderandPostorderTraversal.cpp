// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;
        unordered_map<int, veciter> table;
        for (int i = 0; i < inorder.size(); ++i)
            table.insert({inorder[i], inorder.begin() + i});
        return dfs(inorder.begin(), inorder.end(), postorder.begin(), postorder.end(), table);
    }
private:
    typedef vector<int>::iterator veciter;
    TreeNode* dfs(const veciter& inFirst, const veciter& inSecond, 
                  const veciter& poFirst, const veciter& poSecond, unordered_map<int, veciter>& table) {
        if (inFirst == inSecond || poFirst == poSecond)
            return NULL;
        if (inSecond - inFirst == 1 || poSecond - poFirst == 1)
            return new TreeNode(*poFirst);
        veciter iter = table[*(poSecond - 1)];
        int length = iter - inFirst;
        TreeNode* node = new TreeNode(*iter);
        node->left = dfs(inFirst, iter, poFirst, poFirst + length, table);
        node->right = dfs(iter + 1, inSecond, poFirst + length, poSecond - 1, table);
        return node;
    }   
};