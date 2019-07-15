class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        string result;
        queue<TreeNode*> nodes;
        result += std::to_string(root->val) + ',';
        nodes.push(root);
        while (nodes.size()) {
            TreeNode* node = nodes.front();
            nodes.pop();
            if (node->left) {
                result += std::to_string(node->left->val) + ',';
                nodes.push(node->left);
            } else {
                result += "#,";
            }
            if (node->right) {
                result += std::to_string(node->right->val) + ',';
                nodes.push(node->right);
            } else {
                result += "#,";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        vector<string> vec;
        std::istringstream ss(data);
        std::string token;
        while(std::getline(ss, token, ',')) {
            vec.push_back(token);
        }

        queue<TreeNode*> nodes;
        TreeNode* root = new TreeNode(std::stoi(vec[0]));
        nodes.push(root);

        int pos = 1;
        while (pos != vec.size()) {
            TreeNode *node = nodes.front();
            nodes.pop();
            node->left = newNode(vec[pos++]);
            node->right = newNode(vec[pos++]);
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }

        return root;
    }

private:
    TreeNode* newNode(string val) {
        if (val == "#")
            return NULL;
        return new TreeNode(std::stoi(val));
    }
};