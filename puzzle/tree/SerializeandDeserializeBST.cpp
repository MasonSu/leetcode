// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

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