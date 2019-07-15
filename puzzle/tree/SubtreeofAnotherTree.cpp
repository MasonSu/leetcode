class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == NULL)
            return true;
        bool result = false;
        preOrder(s, t, result);
        return result;        
    }
private:
    void preOrder(TreeNode* root, TreeNode* t, bool& result) {
        if (root == NULL || result)
            return;
        if (root->val == t->val)
            result = sameTree(root, t);
        preOrder(root->left, t, result);
        preOrder(root->right, t, result);
    }
    
    bool sameTree(TreeNode* node1, TreeNode* node2) {
        if (node1 && node2)
            return node1->val == node2->val && sameTree(node1->left, node2->left) && 
                    sameTree(node1->right, node2->right);
        else
            return node1 == node2;
    }
};