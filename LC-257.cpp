/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Helper function to recursively build all root-to-leaf paths
    void allPath(TreeNode* root, string path, vector<string> &ans) {
        // If it's a leaf node, add the path to the result
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Recur on the left subtree if it exists
        if (root->left) {
            allPath(root->left, path + "->" + to_string(root->left->val), ans);
        }

        // Recur on the right subtree if it exists
        if (root->right) {
            allPath(root->right, path + "->" + to_string(root->right->val), ans);
        }
    }

    // Main function to return all root-to-leaf paths in the binary tree
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) return ans; // Handle edge case where tree is empty

        string path = to_string(root->val); // Initialize the path with root value
        allPath(root, path, ans);           // Call the helper function
        return ans;                         // Return the result
    }
};
