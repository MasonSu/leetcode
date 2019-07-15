class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        /* 用空间换时间，根据数值查找对应的迭代器 */
        unordered_map<int, vector<int>::iterator> table;
        for (int i = 0; i < inorder.size(); ++i)
            table.insert({inorder[i], inorder.begin() + i});
        return dfs(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), table);
    }
private:
    /* 这里要用常量引用，因为传递过来的值为右值 */
    TreeNode* dfs(const vector<int>::iterator& preFirst, const vector<int>::iterator& preSecond,
                  const vector<int>::iterator& inFirst, const vector<int>::iterator& inSecond,
                  unordered_map<int, vector<int>::iterator>& table) {
        if (preFirst == preSecond || inFirst == inSecond)
            return NULL;
        if (preSecond - preFirst == 1 || inSecond - inFirst == 1)
            return new TreeNode(*preFirst);
        //vector<int>::iterator iter = std::find(inFirst, inSecond, *preFirst);
        vector<int>::iterator iter = table[*preFirst];
        TreeNode *node = new TreeNode(*iter);
        int length = iter - inFirst;
        node->left = dfs(preFirst + 1, preFirst + length + 1, inFirst, iter, table);
        node->right = dfs(preFirst + length + 1, preSecond, iter + 1, inSecond, table);
        return node;
    }
};