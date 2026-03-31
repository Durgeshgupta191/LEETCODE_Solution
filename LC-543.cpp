/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to calculate the height of a binary tree
    int height(TreeNode* root) {
        if (root == NULL)
            return 0; // Height of empty tree is 0

        // Recursively calculate height of left and right subtrees
        int rightHeight = height(root->right);
        int leftHeight = height(root->left);

        // Return the maximum height of the two subtrees + 1 for the current node
        return max(rightHeight, leftHeight) + 1;
    }

    // Function to calculate the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0; // Diameter of empty tree is 0

        // Recursively find diameter of left and right subtrees
        int leftDm = diameterOfBinaryTree(root->left);
        int rightDm = diameterOfBinaryTree(root->right);

        // Calculate diameter passing through the current root
        // It is the sum of heights of left and right subtrees
        int currDm = height(root->right) + height(root->left);

        // Return the maximum of the three possibilities:
        // 1. Diameter of left subtree
        // 2. Diameter of right subtree
        // 3. Diameter passing through the current root
        return max(currDm, max(leftDm, rightDm));
    }
};
