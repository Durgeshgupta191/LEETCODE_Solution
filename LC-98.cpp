class Solution {
public:
    // Helper function to validate the BST
    // It checks whether the current node's value is within the valid range (min, max)
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        // An empty tree is always a valid BST
        if (root == NULL) {
            return true;
        }

        // If current node's value is not greater than min, it's invalid
        if (min != NULL && root->val <= min->val) {
            return false;
        }

        // If current node's value is not less than max, it's invalid
        if (max != NULL && root->val >= max->val) {
            return false;
        }

        // Recursively validate left subtree:
        // max becomes the current node because all left children must be less than the current node
        // and recursively validate right subtree:
        // min becomes the current node because all right children must be greater than the current node
        return helper(root->left, min, root) &&
               helper(root->right, root, max);
    }

    // Main function to check if a binary tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Call helper with initial min and max as NULL
        return helper(root, NULL, NULL);
    }
};
